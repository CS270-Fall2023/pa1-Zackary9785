token: main.o token.o
	gcc main.o token.o -o token

main.o: main.c token.h
	gcc -c main.c

token.o: token.c token.h
	gcc -c token.c