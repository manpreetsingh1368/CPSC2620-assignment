# Compiler and flags
CXX     := g++
CXXFLAGS:= -Wall -O2
LDFLAGS := -lX11
CXX_INC := -Iinclude

# Directories
SRC_DIR   := src
TEST_DIR  := tests
BUILD_DIR := build

# Files
TARGET := d1a d1b d2a d2b d2c test_zigzag test_multi_turtle
OBJ_EX1 := $(BUILD_DIR)/turtle.o

# Default rule
all: $(TARGET)

# Targets for drivers
d1a: $(OBJ_EX1) $(BUILD_DIR)/driver1a.o
d1b: $(OBJ_EX1) $(BUILD_DIR)/driver1b.o
d2a: $(OBJ_EX1) $(BUILD_DIR)/driver2a.o
d2b: $(OBJ_EX1) $(BUILD_DIR)/driver2b.o
d2c: $(OBJ_EX1) $(BUILD_DIR)/driver2c.o

# Targets for tests
test_zigzag: $(OBJ_EX1) $(BUILD_DIR)/test_zigzag.o
	$(CXX) $^ -o $@ $(LDFLAGS)

test_multi_turtle: $(OBJ_EX1) $(BUILD_DIR)/test_multi_turtle.o
	$(CXX) $^ -o $@ $(LDFLAGS)

# Compile step for src files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CXX_INC) -c $< -o $@

# Compile step for tests files
$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(CXX_INC) -c $< -o $@

# Create build directory if missing
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Clean
clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all clean
