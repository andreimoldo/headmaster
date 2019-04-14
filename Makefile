.SUFFIXES: .cpp .o

CXX = clang++

CXXFLAGS ?= -g -Wall
CXXFLAGS += `pkg-config --cflags xcb`
LDFLAGS   = `pkg-config --libs xcb xcb-util`

SRCDIR   = src
BUILDDIR = obj

WMSRC     = main.cpp manager.cpp
WMHEADERS = manager.hpp
WMOBJECTS = main.o manager.o

WMTARGET = headmaster

all: $(WMTARGET)

$(WMTARGET): $(WMOBJECTS)
	$(CXX) $(LDFLAGS) -o $(WMTARGET) $(WMOBJECTS)

$(WMOBJECTS): $(WMHEADERS) $(WMSRC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

