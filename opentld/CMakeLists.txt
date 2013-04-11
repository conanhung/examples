#Set minimum version requered
cmake_minimum_required(VERSION 2.4.6)
#just to avoid the warning
if(COMMAND cmake_policy)
     cmake_policy(SET CMP0003 NEW)
endif(COMMAND cmake_policy)
#set project name
project(TLD)

#OpenCV
find_package(OpenCV REQUIRED)

#set the include directories
include_directories (${OpenCV_LIBS})

#sources
set ( tld_SRCS
	tld_utils.cpp
	LKTracker.cpp
	FerNNClassifier.cpp
	TLD.cpp
	run_tld.cpp
	)
	
#executables
add_executable(run_tld ${tld_SRCS})
#link the libraries
target_link_libraries(run_tld  ${OpenCV_LIBS})