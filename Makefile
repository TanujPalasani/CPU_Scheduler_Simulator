# Compiler
CXX = g++

# Compiler Flags
CXXFLAGS = -Wall -Wextra -std=c++11

# Directories
SRC_DIR := src
BUILD_DIR := build
INCLUDE_DIR := include

# Source Files (Fixed)
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp) $(wildcard $(SRC_DIR)/*/*/*.cpp)

# Object Files
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRC_FILES))

# Executable Name
TARGET := $(BUILD_DIR)/scheduler.exe

# Default Target
all: $(TARGET)

# Build Executable
$(TARGET): $(OBJ_FILES)
	@if not exist "$(BUILD_DIR)" mkdir "$(BUILD_DIR)"
	$(CXX) $(CXXFLAGS) -I"$(INCLUDE_DIR)" $^ -o $@

# Compile Each Source File (Fixed)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist "$(dir $@)" mkdir "$(dir $@)"
	$(CXX) $(CXXFLAGS) -I"$(INCLUDE_DIR)" -c "$<" -o "$@"

# Clean Build Files (Windows Compatible)
clean:
	@if exist "$(BUILD_DIR)" rmdir /s /q "$(BUILD_DIR)"
	@if exist "$(TARGET)" del /f /q "$(TARGET)"
