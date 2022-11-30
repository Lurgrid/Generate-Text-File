stack_dir = ./stack/
CC = gcc
CFLAGS = -std=c18 \
  -Wall -Wconversion -Werror -Wextra -Wpedantic -Wwrite-strings \
  -O2 \
  -I$(stack_dir)
vpath %.c $(stack_dir)
vpath %.h $(stack_dir)
objects = main.o stack.o
executable = main

all: $(executable)

clean:
	$(RM) $(objects) $(executable)

$(executable): $(objects)
	$(CC) $(objects) -o $(executable)

main.o: main.c stack.h
stack.o: stack.c stack.h
