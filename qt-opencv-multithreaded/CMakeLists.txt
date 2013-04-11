project( qt-opencv-multithreaded )
cmake_minimum_required( VERSION 2.8.8 )
set ( CMAKE_BUILD_TYPE Release )

# Set PATH
set ( CMAKE_PREFIX_PATH "C:\\Qt\\Qt5.0.0\\5.0.0\\msvc2010\\" )
set ( OpenCV_DIR "D:\\Libs\\opencv\\vs2010" )

add_definitions ( -Wall )

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)

# OpenCV
find_package (OpenCV REQUIRED) # tested on 2.4.5

include_directories ( ${OpenCV_LIBS} )

set ( qt-opencv-multithreaded_HDRS
	Config.h
	MatToQImage.h
	Structures.h
	ImageBuffer.h
	)

set ( qt-opencv-multithreaded_SRCS
	main.cpp
	MainWindow.cpp
	MatToQImage.cpp
	FrameLabel.cpp
	CameraView.cpp
	ProcessingThread.cpp
	ImageBuffer.cpp
	CaptureThread.cpp
	CameraConnectDialog.cpp
	ImageProcessingSettingsDialog.cpp
	)

set ( qt-opencv-multithreaded_UIS
	MainWindow.ui
	CameraView.ui
	CameraConnectDialog.ui
	ImageProcessingSettingsDialog.ui
	)
	
QT5_WRAP_UI(UIS ${qt-opencv-multithreaded_UIS})

set ( qt-opencv-multithreaded_MOCS
	MainWindow.h
	FrameLabel.h
	CameraView.h
	ProcessingThread.h
	CaptureThread.h
	CameraConnectDialog.h
	ImageProcessingSettingsDialog.h
	)
	
#QT4_WRAP_CPP(MOCS ${qt-opencv-multithreaded_MOCS})

add_executable ( qt-opencv-multithreaded ${qt-opencv-multithreaded_SRCS} ${UIS} )

target_link_libraries ( qt-opencv-multithreaded ${OpenCV_LIBS} )

# Use the Widgets module from Qt 5.
qt5_use_modules(qt-opencv-multithreaded Widgets)
