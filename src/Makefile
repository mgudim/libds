TARGET = libds.a
BUILD_DIR = ../build/src


SRC_DIR = ./
SRC_FILES := $(subst $(SRC_DIR), , $(shell find $(SRC_DIR) -name "*.c"))
OBJ_FILES = $(addprefix $(BUILD_DIR)/, $(SRC_FILES:.c=.o))
CC = clang
CC_FLAGS = -O2
INC_DIR = ../include
INC_FLAGS = $(addprefix -I, $(INC_DIR))
link: compile
	ar rcs $(BUILD_DIR)/$(TARGET) $(OBJ_FILES)


compile: $(OBJ_FILES)


$(BUILD_DIR)/%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CC_FLAGS) $(INC_FLAGS) -c $< -o $@


extract_libds:
	mkdir -p $(BUILD_DIR)/libds_objs
