project( cvsnakeimage )
cmake_minimum_required( VERSION 2.8.8 )
set ( CMAKE_BUILD_TYPE Release )

add_definitions ( -Wall )

# OpenCV
find_package (OpenCV REQUIRED) # tested on 2.4.5

include_directories ( ${OpenCV_LIBS} )

add_executable ( cvsnakeimage cvsnakeimage.cpp cvsnakes.cpp )

target_link_libraries ( cvsnakeimage ${OpenCV_LIBS} )
