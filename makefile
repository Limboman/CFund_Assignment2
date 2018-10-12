CC=gcc
CFLAGS=-Wall -Werror -ansi -lm
TARGET = Assignment3

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c