BO = build/board.o
MO = build/main.o
CH = ignore/Chess

all: $(CH)

ignore/Chess:ignore build $(BO) $(MO)
	gcc -Wall -Werror -o ignore/Chess $(MO) $(BO)
ignore: 
	mkdir ignore
build/board.o: scr/board.c 
	gcc -Wall -Werror -o $(BO) -c scr/board.c
build/main.o: scr/main.c 
	gcc -Wall -Werror -o $(MO) -c scr/main.c
build:
	mkdir build
.PHONY : clean
clean: 
	rm -rf ignore/
	rm -rf build/*.o
