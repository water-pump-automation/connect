# Compiler
CC = gcc
# Source directory
SRC_DIR = ./src
# Compiler flags
CFLAGS = -I $(SRC_DIR)/core
# Object directory
OBJ_DIR = ./obj
# Source files
SRCS = $(SRC_DIR)/infra/esp32/connect.c
# Object files
OBJS = $(patsubst %.c,%.o,$(SRCS))

# Default rule
all: $(OBJS)
	ld -r $< -o $(OBJ_DIR)/connect.o

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_DIR)/*.o
	@rm $(SRC_DIR)/*/*/*.o