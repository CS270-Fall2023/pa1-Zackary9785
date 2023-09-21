#macros
CC = gcc
FLAGS = -Wall -g

all: token

clean: 
	rm -f token *.o

token: main.o token.o
	$(CC) $(FLAGS) $< token.o -o $@

main.o: main.c token.h
	$(CC) $(FLAGS) -c $<

token.o: token.c token.h
	$(CC) $(FLAGS) -c $<