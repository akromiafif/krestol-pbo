INC_DIRS := inc
SRC_DIR := src
BIN_DIR := bin

LIBS := m
LIB_DIRS :=

CPP_SRC :=
CPP_SRC += $(wildcard $(SRC_DIR)/*.cpp)
CPP_SRC += $(wildcard $(SRC_DIR)/**/*.cpp)

OBJ_FILES :=
OBJ_FILES += $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(CPP_SRC))


INCLUDE_FLAGS := $(foreach DIR,$(INC_DIRS),-I $(DIR))
LIB_FLAGS := $(foreach DIR,$(LIB_DIRS),-L $(DIR)) $(foreach LIB,$(LIBS),-l$(LIB))

BUILD_FLAGS := -Os
LINK_FLAGS := -Os

CC = gcc
CXX = g++
CFLAGS = -Wall -std=c99
CXXFLAGS = -Wall -std=c++11

all: run
.PHONY: all build run

%.o: CXXFLAGS += $(INCLUDE_FLAGS) $(BUILD_FLAGS)
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp $(BIN_DIR)/%.d
	@mkdir -p $(@D)
	@echo Compiling: $<
	@echo Output: $@
	$(CXX) $(CXXFLAGS) -MD -MP -MF $(@:%.o=%.d) -MT $@ -c $< -o $@

$(OBJ_FILES:%.o=%.d):
include $(wildcard $(BIN_DIR)/*.d)

build: CXXFLAGS += $(LIB_FLAGS) $(LINK_FLAGS)
build: $(OBJ_FILES)
	@echo Linking: $^
	@echo Output: $(BIN_DIR)/main
	$(CXX) $(CXXFLAGS) $^ -o $(BIN_DIR)/main

run: build
	@echo Running: $(BIN_DIR)/main
	$(BIN_DIR)/main

.PHONY: clean
clean:
	-rm -rf $(BIN_DIR)

.PHONY: rebuild
rebuild: clean build
