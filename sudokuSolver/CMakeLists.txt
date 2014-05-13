cmake_minimum_required(VERSION 2.8)

project(sudokuSolver)

# Specific to SDK: control the version (major, minor, default patch and )
set(SUDOKUSOLVER_PROJECT_NAME "sudokuSolver")
set(SUDOKUSOLVER_VERSION_MAJOR "1")
set(SUDOKUSOLVER_VERSION_MINOR "0")
set(SUDOKUSOLVER_VERSION_PATCH "0") # patch version for packaging, change when appropriate
string(TOLOWER "${SUDOKUSOLVER_PROJECT_NAME}-${SUDOKUSOLVER_VERSION_MAJOR}.${SUDOKUSOLVER_VERSION_MINOR}" SUDOKUSOLVER_SHORT_VERSION_STRING)

ADD_DEFINITIONS(-DPROJECT_PREFIX="${SUDOKUSOLVER_PROJECT_NAME}")
ADD_DEFINITIONS(-DPROJECT_NAME="${SUDOKUSOLVER_PROJECT_NAME}")

SET(CMAKE_BUILD_TYPE Release)

SET(CMAKE_DEBUG_POSTFIX "d")

####### DEPENDENCIES #######

FIND_PACKAGE(OpenCV REQUIRED) # tested on 2.4.0

include_directories (
	${OpenCV_LIBS}
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	)
	
set ( sudokuSolver_HDRS
	./digitRecognizer.h
	)

set ( sudokuSolver_SRCS
	./digitRecognizer.cpp
	./sudokuSolver.cpp
	)

add_executable ( sudokuSolver ${sudokuSolver_SRCS} )
target_link_libraries ( sudokuSolver ${OpenCV_LIBS} )