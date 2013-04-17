#include <QApplication>
#include "SimpleVTK.h"


////// THIS IS OUR MAIN PROGRAM ENTRANCE POINT ///////////
int main(int argc, char* argv[])
{
  QApplication app( argc, argv );

   ///Create the SimpleVTK Main Window and execute it...
  SimpleVTK simpleVTK_MainWindow;
  simpleVTK_MainWindow.show();

  return app.exec();
}
