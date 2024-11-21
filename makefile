TARGET = surya

CC = gcc

CFLAGS = -Wall -g

SRC = main.c fungsi.c

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)

