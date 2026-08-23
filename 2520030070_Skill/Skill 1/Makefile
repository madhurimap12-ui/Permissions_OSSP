CC = gcc
CFLAGS = -Wall -Wextra
TARGET = process_demo
SOURCE = src/process_demo.c

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
