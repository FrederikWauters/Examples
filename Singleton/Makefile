CURRENT_DIR=$(shell pwd)

SOURCES= $(CURRENT_DIR)/Hit.cpp $(CURRENT_DIR)/Module.cpp $(CURRENT_DIR)/Global.cpp
OBJECTS=$(SOURCES:.cpp=.o)
HEADERS=$(SOURCES:.cpp=.h)


EXECUTABLE=Program

CXXFLAGS= -g3 -O2 -Wall -fPIC -I$(CURRENT_DIR) -std=c++11
CXX = g++

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
