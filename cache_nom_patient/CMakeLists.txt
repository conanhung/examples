project( cache_nom_patient )
cmake_minimum_required( VERSION 2.6 )
set ( CMAKE_BUILD_TYPE Release )
add_definitions ( -Wall )
####### DEPENDENCIES #######
#set ( OpenCV_DIR C:/OpenCV2.4.3/build/ )
FIND_PACKAGE(OpenCV REQUIRED) # tested on 2.4.0

#find_library(IOKIT NAMES IOKit) # APPLE only

include_directories (
	${OpenCV_LIBS}
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	)

set ( cache_nom_patient_SRCS
	cache_nom_patient.cpp
	)

add_executable ( cache_nom_patient ${cache_nom_patient_SRCS} )
target_link_libraries ( cache_nom_patient ${OpenCV_LIBS} )
