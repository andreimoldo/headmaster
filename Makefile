.SUFFIXES: .cpp .o

CXX = clang++

CXXFLAGS += -g -Wall -std=c++0x
CXXFLAGS += `pkg-config --cflags xcb`
LDFLAGS   = `pkg-config --libs xcb xcb-util`

SRCDIR   = src
BUILDDIR = obj

WMSRC     = event_loop.cpp main.cpp manager.cpp
WMHEADERS = event_loop.hpp manager.hpp
WMOBJECTS = event_loop.o main.o manager.o

WMTARGET = headmaster

all: $(WMTARGET)

$(WMTARGET): $(WMOBJECTS)
	$(CXX) $(LDFLAGS) -o $(WMTARGET) $(WMOBJECTS)

$(WMOBJECTS): $(WMHEADERS) $(WMSRC)

.cpp.o:
	$(CXX) $(CXXFLAGS) -o $@ -c $<

