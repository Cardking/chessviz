BO = build/board.o
MO = build/main.o
BRO = build/board_read.o
CH = ignore/Chess

all: $(CH)

ignore/Chess:ignore build $(BO) $(MO) $(BRO)
	gcc -Wall -Werror -g3 -O0 -o ignore/Chess $(MO) $(BO) $(BRO)
ignore: 
	mkdir ignore
build/board.o: scr/board.c 
	gcc -Wall -Werror -o $(BO) -c scr/board.c
build/main.o: scr/main.c 
	gcc -Wall -Werror -o $(MO) -c scr/main.c
build/board_read.o:
	gcc -Wall -Werror -o $(BRO) -c scr/board_read.c
build:
	mkdir build
.PHONY : clean
clean: 
	rm -rf ignore/
	rm -rf build/*.o
