TARGET = run_tests
BUILD_DIR = ../build/test


run_tests: link
	./$(BUILD_DIR)/$(TARGET)


LIBGTEST_PATH = /home/gmock-1.7.0/build/gtest/libgtest.a /home/gmock-1.7.0/build/gtest/libgtest_main.a
LIBDS_PATH = ../build/src/libds.a
LINK_FLAGS =  $(LIBDS_PATH) $(LIBGTEST_PATH)
LINKER = g++
SRC_DIR = ./
SRC_FILES := $(subst $(SRC_DIR), , $(shell find $(SRC_DIR) -name "*.cc"))
INC_DIR = ../include /home/gmock-1.7.0/gtest/include
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.cc=.o))
CC = g++
CC_FLAGS = -O2
INC_FLAGS = $(addprefix -I, $(INC_DIR))
link: compile 
	mkdir -p $(BUILD_DIR)
	$(LINKER) $(OBJ_FILES) $(LINK_FLAGS) -pthread  -o $(BUILD_DIR)/$(TARGET)
compile: $(OBJ_FILES)


$(BUILD_DIR)/%.o: %.cc
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(INC_FLAGS) -c $< -o $@
