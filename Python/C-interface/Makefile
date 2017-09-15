TARGET = main
LIBS = -lm
CC = gcc
CFLAGS = -g -Wall -std=c99 -fPIC

.PHONY: default all clean

default: $(TARGET) libfunctions.so shared_main
all: default

OBJECTS = main.o functions.o
HEADERS = functions.h

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<
	
libfunctions.so: functions.o
	gcc -shared -o libfunctions.so functions.o

$(TARGET): $(OBJECTS) main.c
	$(CC) $(OBJECTS) -Wall $(LIBS) -o $@
	
shared_main: libfunctions.so main.c
	$(CC) -L/home/frederik/Analysis/Examples/Python/C-interface/ $(CFLAGS) -o shared_main main.c -lfunctions -std=c99

clean:
	-rm -f *.o
	-rm -f $(TARGET) shared_main libfunctions.so
