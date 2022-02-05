# Configuaration
CC := gcc
FILE_TYPE := .c
RELEASE_FLAGS := -O3 -DNDEBUG
EXT_HEADERS_DIR := "/usr/include/python3.9"
SRC_DIR := src/C_SRC/
HEADER_DIR := src/C_HEADERS
OBJ_DIR := bin/
LIB_DIR := src/
LIB_NAME := py_mand
BUILD_TARGET := so

LIB := $(LIB_NAME).$(BUILD_TARGET)
LIB_BUILD := $(LIB_DIR)$(LIB)
# Loading in file locations
SRCS := $(wildcard $(SRC_DIR)**/**$(FILE_TYPE)) $(wildcard $(SRC_DIR)*$(FILE_TYPE))
OBJS := $(patsubst $(SRC_DIR)%$(FILE_TYPE), $(OBJ_DIR)%.o, $(SRCS))
# Handling automatic dependency tracking
DEPS := $(patsubst %.o, %.d, $(OBJS))
-include $(DEPS)
DEP_FLAGS = -MMD -MF $(@:.o=.d)

build: $(OBJS)
	@echo "" > .tmp_data
	@echo [INFO] Creating Shared Library [$(BUILD_TARGET)] with Debug Flags ...
	@$(CC) $^ -shared -o $(LIB_BUILD)
	@echo [INFO] [$(LIB)] Created!

$(OBJ_DIR)%.o: $(SRC_DIR)%$(FILE_TYPE)
	@echo [CC] $<
	@mkdir -p $(@D)
	@$(CC) $(RELEASE_FLAGS) $< -c -o $@ -I$(HEADER_DIR) -I$(EXT_HEADERS_DIR) $(DEP_FLAGS) 

.PHONEY: clean
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(DEPS)
	@rm $(LIB_BUILD)
