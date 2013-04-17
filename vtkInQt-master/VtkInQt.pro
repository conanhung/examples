HEADERS += \
    mainwindow.h

SOURCES += \
    mainwindow.cpp \
    main.cpp

FORMS += \
    mainwindow.ui

LIBS    += -L"E:/Dev/VTK5.10.1/build/bin/Debug" -lkernel32 -lgdi32 -lopengl32 -luser32 -lshell32 -lole32 -lcomdlg32 -luuid -ladvapi32 -loleaut32 -lwbemuuid -lglu32 -ld3d9 -lvtkCommon -lvtksys -lQVTK -lvtkViews -lvtkWidgets -lvtkInfovis -lvtkRendering -lvtkGraphics -lvtkImaging -lvtkIO -lvtkFiltering -lvtkVolumeRendering -lvtklibxml2 -lvtkDICOMParser -lvtkpng -lvtkpng -lvtktiff -lvtkzlib -lvtkjpeg -lvtkalglib -lvtkexpat -lvtkverdict -lvtkmetaio -lvtkNetCDF -lvtksqlite -lvtkexoIIc -lvtkftgl -lvtkfreetype -lvtkHybrid

INCLUDEPATH += E:/Dev/VTK5.10.1 E:/Dev/VTK5.10.1/GUISupport/Qt E:/Dev/VTK5.10.1/Common E:/Dev/VTK5.10.1/build E:/Dev/VTK5.10.1/Rendering E:/Dev/VTK5.10.1/build/Rendering E:/Dev/VTK5.10.1/Filtering E:/Dev/VTK5.10.1/Widgets E:/Dev/VTK5.10.1/Graphics E:/Dev/VTK5.10.1/Imaging E:/Dev/VTK5.10.1/IO E:/Dev/VTK5.10.1/VolumeRendering

OTHER_FILES += \
    vm_foot.slc
