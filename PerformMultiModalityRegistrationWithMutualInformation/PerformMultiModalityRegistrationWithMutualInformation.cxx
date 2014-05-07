/*=========================================================================
 *
 *  Copyright Insight Software Consortium
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *         http://www.apache.org/licenses/LICENSE-2.0.txt
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *=========================================================================*/

// The following simple example illustrates how multiple imaging modalities can
// be registered using the ITK registration framework. The first difference
// between this and previous examples is the use of the
// MutualInformationImageToImageMetric as the cost-function to be
// optimized. The second difference is the use of the
// GradientDescentOptimizer. Due to the stochastic nature of the
// metric computation, the values are too noisy to work successfully with the
// RegularStepGradientDescentOptimizer.  Therefore, we will use the
// simpler GradientDescentOptimizer with a user defined learning rate.  The
// following headers declare the basic components of this registration method.
#include "itkImageRegistrationMethod.h"
#include "itkTranslationTransform.h"
#include "itkMutualInformationImageToImageMetric.h"
#include "itkGradientDescentOptimizer.h"


//  One way to simplify the computation of the mutual information is
//  to normalize the statistical distribution of the two input images. The
//  NormalizeImageFilter is the perfect tool for this task.
//  It rescales the intensities of the input images in order to produce an
//  output image with zero mean and unit variance.
#include "itkNormalizeImageFilter.h"

//  Additionally, low-pass filtering of the images to be registered will also
//  increase robustness against noise. In this example, we will use the
//  DiscreteGaussianImageFilter for that purpose.
#include "itkDiscreteGaussianImageFilter.h"


#include "itkImageFileReader.h"
#include "itkImageFileWriter.h"

#include "itkResampleImageFilter.h"
#include "itkCastImageFilter.h"
#include "itkCheckerBoardImageFilter.h"


//  The following section of code implements a Command observer
//  that will monitor the evolution of the registration process.
//
#include "itkCommand.h"
class CommandIterationUpdate : public itk::Command
{
public:
  typedef  CommandIterationUpdate   Self;
  typedef  itk::Command             Superclass;
  typedef  itk::SmartPointer<Self>  Pointer;
  itkNewMacro( Self );

protected:
  CommandIterationUpdate() {};

public:
  typedef   itk::GradientDescentOptimizer     OptimizerType;
  typedef   const OptimizerType   *           OptimizerPointer;

  void Execute(itk::Object *caller, const itk::EventObject & event)
    {
    Execute( (const itk::Object *)caller, event);
    }

  void Execute(const itk::Object * object, const itk::EventObject & event)
    {
    OptimizerPointer optimizer =
      dynamic_cast< OptimizerPointer >( object );
    if( ! itk::IterationEvent().CheckEvent( &event ) )
      {
      return;
      }
    std::cout << optimizer->GetCurrentIteration() << "   ";
    std::cout << optimizer->GetValue() << "   ";
    std::cout << optimizer->GetCurrentPosition() << std::endl;
    }
};


int main( int argc, char *argv[] )
{
  if( argc < 4 )
    {
    std::cerr << "Missing Parameters " << std::endl;
    std::cerr << "Usage: " << argv[0];
    std::cerr << " fixedImageFile";
    std::cerr << " movingImageFile";
    std::cerr << " outputImageFile ";
    std::cerr << " [checkerBoardBefore]";
    std::cerr << " [checkerBoardAfter]" << std::endl;
    return EXIT_FAILURE;
    }
  const char * fixedImageFile = argv[1];
  const char * movingImageFile = argv[2];
  const char * outputImageFile = argv[3];
  const char * checkerBoardBefore = argv[4];
  const char * checkerBoardAfter = argv[5];

  const    unsigned int    Dimension = 2;
  typedef  unsigned short  PixelType;

  typedef itk::Image< PixelType, Dimension >  FixedImageType;
  typedef itk::Image< PixelType, Dimension >  MovingImageType;

  //  It is convenient to work with an internal image type because mutual
  //  information will perform better on images with a normalized statistical
  //  distribution. The fixed and moving images will be normalized and
  //  converted to this internal type.
  typedef float                                      InternalPixelType;
  typedef itk::Image< InternalPixelType, Dimension > InternalImageType;

  typedef itk::TranslationTransform< double, Dimension > TransformType;
  typedef itk::GradientDescentOptimizer                  OptimizerType;
  typedef itk::LinearInterpolateImageFunction<
                                    InternalImageType,
                                    double             > InterpolatorType;
  typedef itk::ImageRegistrationMethod<
                                    InternalImageType,
                                    InternalImageType >  RegistrationType;

  typedef itk::MutualInformationImageToImageMetric<
                                          InternalImageType,
                                          InternalImageType >    MetricType;


  TransformType::Pointer      transform     = TransformType::New();
  OptimizerType::Pointer      optimizer     = OptimizerType::New();
  InterpolatorType::Pointer   interpolator  = InterpolatorType::New();
  RegistrationType::Pointer   registration  = RegistrationType::New();
  MetricType::Pointer         metric        = MetricType::New();

  registration->SetOptimizer(     optimizer     );
  registration->SetTransform(     transform     );
  registration->SetInterpolator(  interpolator  );
  registration->SetMetric( metric  );

  //  The metric requires a number of parameters to be selected, including
  //  the standard deviation of the Gaussian kernel for the fixed image
  //  density estimate, the standard deviation of the kernel for the moving
  //  image density and the number of samples use to compute the densities
  //  and entropy values. Experience has
  //  shown that a kernel standard deviation of 0.4 works well for images
  //  which have been normalized to a mean of zero and unit variance.  We
  //  will follow this empirical rule in this example.
  metric->SetFixedImageStandardDeviation(  0.4 );
  metric->SetMovingImageStandardDeviation( 0.4 );

  typedef itk::ImageFileReader< FixedImageType  > FixedImageReaderType;
  typedef itk::ImageFileReader< MovingImageType > MovingImageReaderType;

  FixedImageReaderType::Pointer  fixedImageReader  =
    FixedImageReaderType::New();
  MovingImageReaderType::Pointer movingImageReader =
    MovingImageReaderType::New();

  fixedImageReader->SetFileName(  fixedImageFile );
  movingImageReader->SetFileName( movingImageFile );

  typedef itk::NormalizeImageFilter<
                                FixedImageType,
                                InternalImageType
                                        > FixedNormalizeFilterType;

  typedef itk::NormalizeImageFilter<
                                MovingImageType,
                                InternalImageType
                                              > MovingNormalizeFilterType;

  FixedNormalizeFilterType::Pointer fixedNormalizer =
                                            FixedNormalizeFilterType::New();

  MovingNormalizeFilterType::Pointer movingNormalizer =
                                            MovingNormalizeFilterType::New();

  typedef itk::DiscreteGaussianImageFilter<
                                      InternalImageType,
                                      InternalImageType
                                                    > GaussianFilterType;

  GaussianFilterType::Pointer fixedSmoother  = GaussianFilterType::New();
  GaussianFilterType::Pointer movingSmoother = GaussianFilterType::New();

  fixedSmoother->SetVariance( 2.0 );
  movingSmoother->SetVariance( 2.0 );

  fixedNormalizer->SetInput(  fixedImageReader->GetOutput() );
  movingNormalizer->SetInput( movingImageReader->GetOutput() );

  fixedSmoother->SetInput( fixedNormalizer->GetOutput() );
  movingSmoother->SetInput( movingNormalizer->GetOutput() );

  registration->SetFixedImage(    fixedSmoother->GetOutput()    );
  registration->SetMovingImage(   movingSmoother->GetOutput()   );


  fixedNormalizer->Update();
  FixedImageType::RegionType fixedImageRegion =
       fixedNormalizer->GetOutput()->GetBufferedRegion();
  registration->SetFixedImageRegion( fixedImageRegion );

  typedef RegistrationType::ParametersType ParametersType;
  ParametersType initialParameters( transform->GetNumberOfParameters() );

  initialParameters[0] = 0.0;  // Initial offset in mm along X
  initialParameters[1] = 0.0;  // Initial offset in mm along Y

  registration->SetInitialTransformParameters( initialParameters );

  //  We should now define the number of spatial samples to be considered in
  //  the metric computation. Note that we were forced to postpone this setting
  //  until we had done the preprocessing of the images because the number of
  //  samples is usually defined as a fraction of the total number of pixels in
  //  the fixed image.
  //
  //  The number of spatial samples can usually be as low as $1\%$ of the total
  //  number of pixels in the fixed image. Increasing the number of samples
  //  improves the smoothness of the metric from one iteration to another and
  //  therefore helps when this metric is used in conjunction with optimizers
  //  that rely of the continuity of the metric values. The trade-off, of
  //  course, is that a larger number of samples result in longer computation
  //  times per every evaluation of the metric.
  //
  //  It has been demonstrated empirically that the number of samples is not a
  //  critical parameter for the registration process. When you start fine
  //  tuning your own registration process, you should start using high values
  //  of number of samples, for example in the range of 20% to 50% of the
  //  number of pixels in the fixed image. Once you have succeeded to register
  //  your images you can then reduce the number of samples progressively until
  //  you find a good compromise on the time it takes to compute one evaluation
  //  of the Metric. Note that it is not useful to have very fast evaluations
  //  of the Metric if the noise in their values results in more iterations
  //  being required by the optimizer to converge.
  //  behavior of the metric values as the iterations progress.
  const unsigned int numberOfPixels = fixedImageRegion.GetNumberOfPixels();

  const unsigned int numberOfSamples =
                        static_cast< unsigned int >( numberOfPixels * 0.01 );

  metric->SetNumberOfSpatialSamples( numberOfSamples );

  //  Since larger values of mutual information indicate better matches than
  //  smaller values, we need to maximize the cost function in this example.
  //  By default the GradientDescentOptimizer class is set to minimize the
  //  value of the cost-function. It is therefore necessary to modify its
  //  default behavior by invoking the MaximizeOn() method.
  //  Additionally, we need to define the optimizer's step size using the
  //  SetLearningRate() method.
  optimizer->SetNumberOfIterations( 200 );
  optimizer->MaximizeOn();

  // Note that large values of the learning rate will make the optimizer
  // unstable. Small values, on the other hand, may result in the optimizer
  // needing too many iterations in order to walk to the extrema of the cost
  // function. The easy way of fine tuning this parameter is to start with
  // small values, probably in the range of {5.0, 10.0}. Once the other
  // registration parameters have been tuned for producing convergence, you
  // may want to revisit the learning rate and start increasing its value until
  // you observe that the optimization becomes unstable.  The ideal value for
  // this parameter is the one that results in a minimum number of iterations
  // while still keeping a stable path on the parametric space of the
  // optimization. Keep in mind that this parameter is a multiplicative factor
  // applied on the gradient of the Metric. Therefore, its effect on the
  // optimizer step length is proportional to the Metric values themselves.
  // Metrics with large values will require you to use smaller values for the
  // learning rate in order to maintain a similar optimizer behavior.
  optimizer->SetLearningRate( 15.0 );

  CommandIterationUpdate::Pointer observer = CommandIterationUpdate::New();
  optimizer->AddObserver( itk::IterationEvent(), observer );

  try
    {
    registration->Update();
    std::cout << "Optimizer stop condition: "
              << registration->GetOptimizer()->GetStopConditionDescription()
              << std::endl;
    }
  catch( itk::ExceptionObject & err )
    {
    std::cout << "ExceptionObject caught !" << std::endl;
    std::cout << err << std::endl;
    return EXIT_FAILURE;
    }

  ParametersType finalParameters = registration->GetLastTransformParameters();

  double TranslationAlongX = finalParameters[0];
  double TranslationAlongY = finalParameters[1];

  unsigned int numberOfIterations = optimizer->GetCurrentIteration();

  double bestValue = optimizer->GetValue();

  // Print out results
  std::cout << std::endl;
  std::cout << "Result = " << std::endl;
  std::cout << " Translation X = " << TranslationAlongX  << std::endl;
  std::cout << " Translation Y = " << TranslationAlongY  << std::endl;
  std::cout << " Iterations    = " << numberOfIterations << std::endl;
  std::cout << " Metric value  = " << bestValue          << std::endl;
  std::cout << " Numb. Samples = " << numberOfSamples    << std::endl;


  typedef itk::ResampleImageFilter<
                            MovingImageType,
                            FixedImageType >    ResampleFilterType;

  TransformType::Pointer finalTransform = TransformType::New();

  finalTransform->SetParameters( finalParameters );
  finalTransform->SetFixedParameters( transform->GetFixedParameters() );

  ResampleFilterType::Pointer resample = ResampleFilterType::New();

  resample->SetTransform( finalTransform );
  resample->SetInput( movingImageReader->GetOutput() );

  FixedImageType::Pointer fixedImage = fixedImageReader->GetOutput();

  resample->SetSize(    fixedImage->GetLargestPossibleRegion().GetSize() );
  resample->SetOutputOrigin(  fixedImage->GetOrigin() );
  resample->SetOutputSpacing( fixedImage->GetSpacing() );
  resample->SetOutputDirection( fixedImage->GetDirection() );
  resample->SetDefaultPixelValue( 100 );


  typedef  unsigned char  OutputPixelType;

  typedef itk::Image< OutputPixelType, Dimension > OutputImageType;

  typedef itk::CastImageFilter<
                        FixedImageType,
                        OutputImageType > CastFilterType;

  typedef itk::ImageFileWriter< OutputImageType >  WriterType;

  WriterType::Pointer      writer =  WriterType::New();
  CastFilterType::Pointer  caster =  CastFilterType::New();

  writer->SetFileName( outputImageFile );
  caster->SetInput( resample->GetOutput() );
  writer->SetInput( caster->GetOutput()   );
  writer->Update();


  // Generate checkerboards before and after registration
  typedef itk::CheckerBoardImageFilter< FixedImageType >
    CheckerBoardFilterType;

  CheckerBoardFilterType::Pointer checker = CheckerBoardFilterType::New();

  checker->SetInput1( fixedImage );
  checker->SetInput2( resample->GetOutput() );

  caster->SetInput( checker->GetOutput() );
  writer->SetInput( caster->GetOutput()   );

  // Before registration
  TransformType::Pointer identityTransform = TransformType::New();
  identityTransform->SetIdentity();
  resample->SetTransform( identityTransform );

  if( argc > 4 )
    {
    writer->SetFileName( checkerBoardBefore );
    writer->Update();
    }

  // After registration
  resample->SetTransform( finalTransform );
  if( argc > 5 )
    {
    writer->SetFileName( checkerBoardAfter );
    writer->Update();
    }

  return EXIT_SUCCESS;
}
