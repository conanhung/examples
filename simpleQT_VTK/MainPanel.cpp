
#include "MainPanel.h"

#include <QFileDialog>
#include <QInputDialog>

#include <fstream>

class MainWindow;

// Constructor
MainPanel::MainPanel( QWidget* parent ) : QDockWidget( parent )
{
	//Just call this to setup the GUI using QT UI file
	// this function was generated by UI compiler and MOC compiler automatically (by QT)
    setupUi( this ); 

}//end of constructor


// Destructor
MainPanel::~MainPanel()
{


}//end of destructor

