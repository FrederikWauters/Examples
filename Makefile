CXX = g++

ROOT_CFLAGS = `$(ROOTSYS)/bin/root-config --cflags --glibs`
ROOT_LIBS = `$(ROOTSYS)/bin/root-config --libs --glibs` -lTree

CURRENT_DIR=$(shell pwd)

SOURCES= $(CURRENT_DIR)/DataManager.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h)



EXECUTABLE=Program

CXXFLAGS= -g -O2 -Wall $(ROOT_CFLAGS) -fPIC -I$(ROOTSYS)/include -I$(CURRENT_DIR)
LDFLAGS=$(ROOT_LIBS)


all: $(EXECUTABLE) 

$(EXECUTABLE): main.cpp $(OBJECTS) 
	$(CXX)  $(CXXFLAGS) -o $@ $^ $(LDFLAGS)



print:
	@echo "Objects $(OBJECTS)"
	@echo "Headers $(HEADERS)"

.PHONY: clean

clean:
	rm *.o 
	rm *~
