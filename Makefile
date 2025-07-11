#Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Iinclude

# Source and object files
SRC = main.c src/REPL.c src/compiler.c
OBJ = $(SRC:.c=.o)

# Output executable
TARGET = tinyDB

# Default rule
all: $(TARGET)

# Rule to build the final executable
$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $@

# Rule to build .o files from .c
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJ) $(TARGET)