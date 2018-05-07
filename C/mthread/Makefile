TARGET = program
LIBS = -lm -lpthread
CC = gcc
CFLAGS = -g -Wall -I$(INC_DIR) -std=c99

.PHONY: default all clean

default: $(TARGET)
all: default


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
