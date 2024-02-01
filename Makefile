CC = g++
CFLAGS = -std=c++11
SFML_LIBS = -lsfml-audio -lsfml-window -lsfml-graphics -lsfml-system -lsfml-network

SRC_DIR = src
INCLUDE_DIR = include
BIN_DIR = bin

SFML_INCLUDE = -I/usr/include/SFML
SFML_LIB_PATH = -L/usr/lib/x86_64-linux-gnu

SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))

TARGET = $(BIN_DIR)/flappybird

all: $(TARGET)
	./$(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(SFML_INCLUDE) $(SFML_LIB_PATH) -o $@ $^ $(SFML_LIBS)

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(SFML_INCLUDE) -c -o $@ $<

clean:
	rm -rf $(BIN_DIR)/*

.PHONY: all clean
