INC_DIR 	= $(MIDASSYS)/include
LIB_DIR 	= $(MIDASSYS)/linux/lib

TARGET = program
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -I$(INC_DIR)

.PHONY: default all clean

default: $(TARGET)
all: default

LIB = $(LIB_DIR)/libmidas.a

OBJECTS = $(patsubst %.c, %.o, $(wildcard *.c))
HEADERS = $(wildcard *.h)


%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

.PRECIOUS: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -Wall $(LIBS) $(LIB) -o $@ 

clean:
	-rm -f *.o
	-rm -f $(TARGET)
