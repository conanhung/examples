#include <vtkVersion.h>
#include <vtkSmartPointer.h>

#include <string>

#include <vtkActor.h>
#include <vtkFieldData.h>
#include <vtkImageAccumulate.h>
#include <vtkImageData.h>
#include <vtkImageExtractComponents.h>
#include <vtkMetaImageReader.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkXYPlotActor.h>
#include <vtkImageMagnitude.h>

int main(int argc, char *argv[])
{
    // Handle the arguments
    if( argc < 2 )
    {
        std::cout << "Required arguments: image.mha" << std::endl;
        return EXIT_FAILURE;
    }

    std::string inputFilename;
    inputFilename = argv[1];

    // Read Meta image
    vtkSmartPointer<vtkMetaImageReader> reader =
        vtkSmartPointer<vtkMetaImageReader>::New();
    reader->SetFileName(inputFilename.c_str());
    reader->Update();

    // Histogram

    // Create a vtkXYPlotActor
    vtkSmartPointer<vtkXYPlotActor> plot =
        vtkSmartPointer<vtkXYPlotActor>::New();
    plot->SetTitle("Histogram");
    plot->ExchangeAxesOff();
    plot->SetLabelFormat( "%g" );
    plot->SetXTitle( "Level" );
    plot->SetYTitle( "" );
    plot->SetXValuesToValue();
    
    double ymax = 0.;

    double red[3] = {1, 0, 0 };

    // Process the image, extracting and plotting a histogram

    double range[2];
    reader->GetOutput()->GetScalarRange( range );
    
    //std::cout << "rang 0 : " << range[0] << std::endl;
    //std::cout << "rang 1 : " << range[1] << std::endl;

    vtkSmartPointer<vtkImageAccumulate> histogram =
        vtkSmartPointer<vtkImageAccumulate>::New();
    histogram->SetInputConnection( reader->GetOutputPort() );
    histogram->SetComponentExtent(
        static_cast<int>(range[0]),
        static_cast<int>(range[1])-1,0,0,0,0 );
    histogram->SetComponentOrigin( range[0],0,0 );
    histogram->SetComponentSpacing( 1,0,0 );
    histogram->IgnoreZeroOn();
    histogram->Update();
    
    if( histogram->GetOutput()->GetScalarRange()[1] > ymax )
    {
        ymax = histogram->GetOutput()->GetScalarRange()[1];
    }

#if VTK_MAJOR_VERSION <= 5
    plot->AddInput( histogram->GetOutput() );
#else
    plot->AddDataSetInputConnection( histogram->GetOutputPort() );
#endif
    plot->SetPlotColor(0,red);
    //plot->SetPlotLabel(0,"Histogram");
    //plot->LegendOn();


    plot->SetXRange( range[0], range[1] );
    plot->SetYRange( 0, ymax );

    // Visualize the histogram(s)
    vtkSmartPointer<vtkRenderer> renderer =
        vtkSmartPointer<vtkRenderer>::New();
    renderer->AddActor(plot);

    vtkSmartPointer<vtkRenderWindow> renderWindow =
        vtkSmartPointer<vtkRenderWindow>::New();
    renderWindow->AddRenderer( renderer );
    renderWindow->SetSize(640, 480);

    vtkSmartPointer<vtkRenderWindowInteractor> interactor =
        vtkSmartPointer<vtkRenderWindowInteractor>::New();
    interactor->SetRenderWindow( renderWindow );

    // Initialize the event loop and then start it
    interactor->Initialize();
    interactor->Start();

    return EXIT_SUCCESS;
}