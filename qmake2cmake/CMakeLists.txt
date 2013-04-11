project(qm2cm)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(qm2cm_SRCS converter.cpp qm2cm.cpp main.cpp)
set(qm2cm_UIS qm2cm.ui)

qt4_wrap_ui(qm2cm_wrapped_UIS ${qm2cm_UIS})
qt4_automoc(${qm2cm_SRCS})

add_executable(qm2cm ${qm2cm_SRCS} ${qm2cm_wrapped_UIS})
target_link_libraries(qm2cm ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
