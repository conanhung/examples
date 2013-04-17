#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <vtkSmartPointer.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkActor.h>
#include <vtkRenderer.h>
#include <vtkImageData.h>
#include <vtkImagePlaneWidget.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkActor.h>
#include <vtkSLCReader.h>
#include <vtkImageThreshold.h>
#include <vtkContourFilter.h>
#include <vtkVolumeTextureMapper2D.h>
#include <vtkVolume.h>
#include <vtkColorTransferFunction.h>
#include <vtkPiecewiseFunction.h>
#include <vtkVolumeProperty.h>


#include "vtkSmartPointer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    vtkSLCReader *slcreader = vtkSLCReader::New();
    slcreader->SetFileName("vm_foot.slc");

    vtkVolumeTextureMapper2D *negMapper = vtkVolumeTextureMapper2D::New();
    negMapper->SetInput(slcreader->GetOutput());

    m_opacityFunction = vtkPiecewiseFunction::New();

    m_colorTransferFunction = vtkColorTransferFunction::New();

    vtkVolumeProperty *vol = vtkVolumeProperty::New();
    vol->SetColor(m_colorTransferFunction);
    vol->SetScalarOpacity(m_opacityFunction);


    Update();

    vtkVolume *volume = vtkVolume::New();
    volume->SetMapper(negMapper);
    volume->SetProperty(vol);


    vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();

    renderer->AddVolume(volume);
    renderer->ResetCamera();


    this->ui->qVtkWidget->GetRenderWindow()->AddRenderer(renderer);

}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Update()
{
    // Zone 1
    float intensity1 = this->ui->IntensitySpinBox->value();

    float redInit = this->ui->RedInitSpinBox->value();
    float redFinal = this->ui->RedFinalSpinBox->value();

    float greenInit = this->ui->GreenInitSpinBox->value();
    float greenFinal = this->ui->GreenFinalSpinBox->value();

    float blueInit = this->ui->BlueInitSpinBox->value();
    float blueFinal = this->ui->BlueFinalSpinBox->value();

    float alphaInit = this->ui->AlphaInitSpinBox->value();
    float alphaFinal = this->ui->AlphaFinalSpinBox->value();


    // Zone 2
    float intensity2 = this->ui->Intensity2SpinBox->value();

    float red2Init = this->ui->Red2InitSpinBox->value();
    float red2Final = this->ui->Red2FinalSpinBox->value();

    float green2Init = this->ui->Green2InitSpinBox->value();
    float green2Final = this->ui->Green2FinalSpinBox->value();

    float blue2Init = this->ui->Blue2InitSpinBox->value();
    float blue2Final = this->ui->Blue2FinalSpinBox->value();

    float alpha2Init = this->ui->Alpha2InitSpinBox->value();
    float alpha2Final = this->ui->Alpha2FinalSpinBox->value();


    // Color Transfer funcions
    m_colorTransferFunction->RemoveAllPoints();

    m_colorTransferFunction->AddRGBPoint(0,0,0,0);
    m_colorTransferFunction->AddRGBPoint(intensity1,0,0,0);

    m_colorTransferFunction->AddRGBPoint(intensity1+1,redInit,greenInit,blueInit);
    m_colorTransferFunction->AddRGBPoint(intensity2,redFinal,greenFinal,blueFinal);

    m_colorTransferFunction->AddRGBPoint(intensity2+1,red2Init,green2Init,blue2Init);
    m_colorTransferFunction->AddRGBPoint(255,red2Final,green2Final,blue2Final);


    // Opacity Transfer funcion
    m_opacityFunction->RemoveAllPoints();

    m_opacityFunction->AddPoint(0,0);
    m_opacityFunction->AddPoint(intensity1,0);

    m_opacityFunction->AddPoint(intensity1+1,alphaInit);
    m_opacityFunction->AddPoint(intensity2,alphaFinal);

    m_opacityFunction->AddPoint(intensity2+1,alpha2Init);
    m_opacityFunction->AddPoint(255,alpha2Final);


    // Refresh the widget to reflect changes.
    ui->qVtkWidget->repaint();
}
