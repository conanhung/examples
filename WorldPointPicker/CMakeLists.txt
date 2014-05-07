
cmake_minimum_required(VERSION 2.8)

PROJECT(WorldPointPicker)

find_package(VTK REQUIRED)
include(${VTK_USE_FILE})

#add_executable(WorldPointPicker MACOSX_BUNDLE WorldPointPicker)
add_executable(WorldPointPicker WorldPointPicker)

if(VTK_LIBRARIES)
  target_link_libraries(WorldPointPicker ${VTK_LIBRARIES})
else()
  target_link_libraries(WorldPointPicker vtkHybrid)
endif()
