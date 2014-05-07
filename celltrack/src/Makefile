# if you are lucky, updating the first two lines below to reflect
#  the paths where you installed OpenCV and wxWidgets should be sufficient.
# You might need to update other paths and libraries further down depending
#  on your specific openCV and wxWidgets installation paths and library names.
# Please give us feedback about your Makefile experience if you think your
#  feedback would benefit other users too.

CV_ROOT = "/usr/include/opencv"
WX_ROOT = "/usr/include/wx-2.8/wx"
CXX     = g++

CV_INCFLAGS = -I"$(CV_ROOT)/cxcore/include" -I"$(CV_ROOT)/cxcore/include" -I"$(CV_ROOT)/cvaux/include" -I"$(CV_ROOT)/ml/include" -I"$(CV_ROOT)/otherlibs/highgui" -I"$(CV_ROOT)/otherlibs/cvcam/include" -I"$(CV_ROOT)/src"
CV_LDFLAGS   = -L"$(CV_ROOT)/lib" -lcv -lcxcore -lhighgui -lcvaux -lcvcam -lcvhaartraining -lcxts -ltrs


WX_INCFLAGS = -I"$(WX_ROOT)/inc"
WX_CONF = "$(WX_ROOT)/wx-config.in"
WX_CXXFLAGS = `$(WX_CONF) --cxxflags`
WX_LDFLAGS  = `$(WX_CONF) --ldflags`
WX_LDLIBS   = `$(WX_CONF) --libs`
WX_REZFLAGS = `$(WX_CONF) --rez-flags`

#if wx_conf gives problems, try the following:
#WX_INCFLAGS = -I"$(WX_ROOT)/include" -I"$(WX_ROOT)/include/wx" -I"$(WX_ROOT)/contrib/include"
#WX_LDFLAGS  = -L"$(WX_ROOT)/lib"
#WX_LDLIBS   = -lwxbase28_xml -lwxmsw28_core -lwxbase28 -lwxtiff -lwxjpeg -lwxpng -lwxzlib -lwxregex -lwxexpat

CT_INCFLAGS = -I"lib/wxmathplot-0.03" -I"plugins" -I"gui" -I"gui/images"

all: celltrack.exe

celltrack.exe: *.cpp lib/wxmathplot-0.03/*.cpp gui/*.cpp plugins/*.cpp
	@echo $@
	@$(CXX) $(CV_INCFLAGS) $(CV_LDFLAGS) $(WX_INCFLAGS) $(WX_LDFLAGS) $(WX_LDLIBS) $(CT_INCFLAGS) -o $@ $< 

