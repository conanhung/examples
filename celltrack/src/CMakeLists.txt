PROJECT(CellTrack)


FIND_PACKAGE(wxWidgets REQUIRED html adv core base net aui xrc qa richtext)
INCLUDE(${wxWidgets_USE_FILE})

FIND_PACKAGE(OpenCV REQUIRED)

include_directories (
	${OpenCV_LIBS}
	${CMAKE_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR}
	)

ADD_EXECUTABLE(CellTrack MyApp.cpp)
TARGET_LINK_LIBRARIES(CellTrack ${wxWidgets_LIBRARIES} ${OpenCV_LIBS})
