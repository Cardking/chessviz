all: compile

compile: ignore
	gcc -Wall -o ignore/Chess Chess.c

ignore: 
	mkdir ignore
