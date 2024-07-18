CC=gcc
INCLUDE_LOCATION=/opt/homebrew/include
LIB_LOCATION=/opt/homebrew/lib
CFLAGS=-I$(INCLUDE_LOCATION) -L$(LIB_LOCATION) -lglfw -framework OpenGL
SRCS=main.c ./window/render.c ./game/block.c
TARGET=main

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(SRCS) -o $(TARGET) $(CFLAGS)

clean:
	rm -f $(TARGET)