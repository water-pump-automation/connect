# Compiler
CC = gcc
# Source directory
SRC_DIR = ./src
# Load directory
LOAD_DIR = ./load
# Compiler flags
CFLAGS = -I ./headers
# Object directory
OBJ_DIR = ./obj

esp32: $(patsubst %.c,%.o,$(SRC_DIR)/esp32/connect.c) $(patsubst %.c,%.o,$(LOAD_DIR)/load.c)
	ld -r $^ $(CFLAGS) -o $(OBJ_DIR)/connect.o

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LOAD_DIR)/%.o: $(LOAD_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm $(OBJ_DIR)/*.o
	@rm $(SRC_DIR)/esp32/*.o
	@rm $(LOAD_DIR)/*.o