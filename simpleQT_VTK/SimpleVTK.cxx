#include "ui_SimpleVTK.h"
#include "SimpleVTK.h"



// Constructor
SimpleVTK::SimpleVTK()
{
  this->ui = new Ui_SimpleVTK;
  this->ui->setupUi(this);

  connect(this->ui->verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(setSlice()));

  QString dirName("data/");

  // Load source
  vtkSmartPointer<vtkDICOMImageReader> reader =
    vtkSmartPointer<vtkDICOMImageReader>::New();
  reader->SetDirectoryName(dirName.toAscii().data());
  reader->Update();

  // Mapper
  /*vtkSmartPointer<vtkPolyDataMapper> mapper =vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
  vtkSmartPointer<vtkActor> actor =vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);*/

  // VTK Renderer
  /*vtkSmartPointer<vtkRenderer> renderer =vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);*/

  ////// Setup and add text to 3D render window
  /*vtkSmartPointer<vtkTextActor> textActor = vtkSmartPointer<vtkTextActor>::New();
  textActor->GetTextProperty()->SetFontSize ( 15 );
  textActor->SetPosition2 ( 10.0, 40.0 );
  renderer->AddActor2D ( textActor );
  textActor->SetInput ( "This is sample text on 3D rendering window" );
  textActor->GetTextProperty()->SetColor (0.0,0.0,1.0 );*/
  /////////////////////////////////////////////////////////////////////////////////////

  //Define the background color of rendering window
  //renderer->SetBackground ( 0.6,1,1 );

  // Visualize
  imageViewer = vtkSmartPointer<vtkImageViewer2>::New();
  imageViewer->SetInputConnection(reader->GetOutputPort());
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor =
    vtkSmartPointer<vtkRenderWindowInteractor>::New();
  imageViewer->SetupInteractor(renderWindowInteractor);
  imageViewer->Render();
  imageViewer->GetRenderer()->ResetCamera();
  imageViewer->SetSlice(150);
  imageViewer->Render();

	imageViewer->SetInputConnection(reader->GetOutputPort());
	this->ui->qvtkWidget->SetRenderWindow(imageViewer->GetRenderWindow());
	imageViewer->SetupInteractor(this->ui->qvtkWidget->GetRenderWindow()->GetInteractor());
 
	this->ui->qvtkWidget->show();

  // Connect VTK with Qt with Renderer
  //this->ui->qvtkWidget->GetRenderWindow()->AddRenderer(renderWindowInteractor);

  //Finally add the Main Control Panel that we created to SimpleVTK window
   m_mainPanel = NULL;
   addMainPanel();
};

void SimpleVTK::setSlice()
{
	imageViewer->SetSlice(this->ui->verticalSlider->value());
	
	imageViewer->Render();
}

//Destructor
SimpleVTK::~SimpleVTK()
{
    if(m_mainPanel) delete m_mainPanel;

}


/////////////////////////////////////////////////////////////////////////////////
/////////////// Our user defined functions here /////////////////////////////////

void SimpleVTK::addMainPanel()
{

    // ----- show Tumor Segmentation panel -----
     if( !m_mainPanel )
     {
         Qt::WindowFlags flags = Qt::SubWindow;

         m_mainPanel = new MainPanel(this);
         m_mainPanel->setWindowFlags( flags );
		 m_mainPanel->setFixedWidth(275);

		 //mainpanel is actually QDockWidget
		 addDockWidget(Qt::LeftDockWidgetArea, m_mainPanel);

		 m_mainPanel->show();
     }
     else
         m_mainPanel->show();

}


//// Note that "actions" in QT are actually triggered events from Menus ///
// Creating and adding menus should also be done in QT Designer...
void SimpleVTK::on_actionExit_2_triggered()
{
    //Just exit from program...
    exit(0);
}

void SimpleVTK::on_actionAbout_triggered()
{
    QMessageBox messageBox;
    messageBox.setWindowTitle("About");
	messageBox.setText("Simple 2D/3D rendering program \nbased on QT and VTK libraries...");
	//messageBox.setInformativeText("");
	messageBox.setStandardButtons(QMessageBox::Ok);
	messageBox.exec();
}



