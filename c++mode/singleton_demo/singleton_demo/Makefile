CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Werror -O2 -pthread
INCLUDES := -Iinclude

BUILD_DIR := build
SRC_DIR := src
APP_DIR := app
TEST_DIR := tests

LOGGER_SRC := $(SRC_DIR)/Logger.cpp
MAIN_SRC := $(APP_DIR)/main.cpp
TEST_SRC := $(TEST_DIR)/test_logger.cpp

APP_TARGET := $(BUILD_DIR)/singleton_demo
TEST_TARGET := $(BUILD_DIR)/test_logger

.PHONY: all run test clean debug

all: $(APP_TARGET)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(APP_TARGET): $(LOGGER_SRC) $(MAIN_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(TEST_TARGET): $(LOGGER_SRC) $(TEST_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

run: $(APP_TARGET)
	./$(APP_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

debug: CXXFLAGS := -std=c++17 -Wall -Wextra -g -O0 -pthread
debug: clean all

clean:
	rm -rf $(BUILD_DIR) app.log test_logger.log