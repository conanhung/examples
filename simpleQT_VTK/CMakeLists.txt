cmake_minimum_required(VERSION 2.6)
PROJECT(SimpleVTK)
 
FIND_PACKAGE(VTK)
INCLUDE(${VTK_USE_FILE})
 
FIND_PACKAGE(Qt4 REQUIRED)
INCLUDE(${QT_USE_FILE})

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR} )
 
SET(SimpleViewSrcs Main.cxx SimpleVTK.cxx MainPanel.cpp)
SET(SimpleViewUI SimpleVTK.ui MainPanel.ui)
SET(SimpleViewHeaders SimpleVTK.h MainPanel.h)
 
QT4_WRAP_UI(UISrcs ${SimpleViewUI})
QT4_WRAP_CPP(MOCSrcs ${SimpleViewHeaders} )
 
ADD_EXECUTABLE( SimpleVTK ${SimpleViewSrcs} ${UISrcs} ${MOCSrcs})
TARGET_LINK_LIBRARIES( SimpleVTK QVTK )
