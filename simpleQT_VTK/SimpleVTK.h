// This is the header for SimpleVTK class
// SimpleVTK inherit teh QMainWindow and SimpleVTK.ui (UI_SimpleVTK) UI file 
// genrated by QT Designer

#ifndef SimpleVTK_H
#define SimpleVTK_H

#include <vtkSmartPointer.h>
#include <QMainWindow>



#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkDICOMImageReader.h>

#include <vtkTextActor.h>
#include <vtkTextProperty.h>

#include <QMessageBox>


#include "MainPanel.h"


// Forward Qt class declarations
class Ui_SimpleVTK;

class SimpleVTK : public QMainWindow
{
  Q_OBJECT
public:

  // Constructor/Destructor
  SimpleVTK();
  ~SimpleVTK();

  void addMainPanel();

 public slots:
  // Thiha : Add all triggering function here...
  // Creation of triggering functions and definitions should do in QT Designer for easiness
  void on_actionAbout_triggered();
  void on_actionExit_2_triggered();
  void setSlice();


 private:
  Ui_SimpleVTK *ui;


  //Pointer to mainPanel widget (we will add our MainPanel to this Main Window)
  MainPanel* m_mainPanel;

  vtkSmartPointer<vtkImageViewer2> imageViewer;

};

#endif
