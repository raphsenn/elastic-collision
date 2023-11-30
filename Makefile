CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -pedantic
LDFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

.PHONY: all clean format

all: compile

compile: $(OBJS)
	$(CXX) $(CXXFLAGS) -o main $(OBJS) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

format:
	clang-format -i $(SRC_DIR)/*.cpp $(INCLUDE_DIR)/*.h

clean:
	rm -f main
	rm -f $(BUILD_DIR)/*.o
	rm -rf $(BUILD_DIR)
