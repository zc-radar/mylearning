CXX := g++

CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude -Iinclude/notification
LDFLAGS :=

APP_TARGET := bin/notify
TEST_TARGET := bin/factory_test

SRC := $(shell find src -name '*.cpp')
APP_OBJ := $(SRC:%.cpp=build/%.o)

LIB_SRC := $(filter-out src/main.cpp,$(SRC))
LIB_OBJ := $(LIB_SRC:%.cpp=build/%.o)

TEST_SRC := tests/FactoryTest.cpp
TEST_OBJ := $(TEST_SRC:%.cpp=build/%.o)

APP_DEP := $(APP_OBJ:.o=.d)
TEST_DEP := $(TEST_OBJ:.o=.d)

.PHONY: all clean run test debug help

all: $(APP_TARGET)

$(APP_TARGET): $(APP_OBJ) | bin
	$(CXX) $(CXXFLAGS) $(APP_OBJ) -o $@ $(LDFLAGS)

$(TEST_TARGET): $(LIB_OBJ) $(TEST_OBJ) | bin
	$(CXX) $(CXXFLAGS) $(LIB_OBJ) $(TEST_OBJ) -o $@ $(LDFLAGS)

build/src/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

build/tests/%.o: tests/%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

bin:
	mkdir -p bin

run: all
	./$(APP_TARGET) $(ARGS)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

debug: CXXFLAGS += -g -O0
debug: clean all

clean:
	rm -rf build bin

help:
	@echo "Available commands:"
	@echo "  make                 Build the application"
	@echo "  make run ARGS='...' Run the application"
	@echo "  make test            Run tests"
	@echo "  make debug           Debug build"
	@echo "  make clean           Remove build files"

-include $(APP_DEP)
-include $(TEST_DEP)
