CFLAGS = -g -std=c99 -Wall -Wextra -pedantic -Werror

all: lab3

lab3: lab3.o
	gcc $(CFLAGS) -o $@ $^

lab3.o: lab3.c
	gcc $(CFLAGS) -c $^
clean:
	rm lab3.o
	rm lab3
