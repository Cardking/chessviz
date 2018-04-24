BO = build/scr/board.o
MO = build/scr/main.o
BRO = build/scr/board_read.o
BOT = build/test/board_test.o
MOT = build/test/main.o
BROT = build/test/board_read_test.o
CH = ignore/Chess
CT = ignore/ctest

all: $(CH)

test: ignore/ctest
	./ignore/ctest
ignore/Chess:ignore build build/scr $(BO) $(MO) $(BRO)
	gcc -Wall -Werror -g3 -O0 -o ignore/Chess $(MO) $(BO) $(BRO)
ignore/ctest:ignore build build/test $(BOT) $(MOT) $(BROT)
	gcc -Wall -Werror -o $(CT) $(BOT) $(MOT) $(BROT)
ignore: 
	mkdir ignore
build/scr/board.o: scr/board.c 
	gcc -Wall -Werror -o $(BO) -c scr/board.c
build/scr/main.o: scr/main.c 
	gcc -Wall -Werror -o $(MO) -c scr/main.c
build/scr/board_read.o:
	gcc -Wall -Werror -o $(BRO) -c scr/board_read.c
build/test/board_test.o: scr/board.c 
	gcc -Wall -Werror -o $(BOT) -c test/board.c
build/test/main.o: scr/main.c 
	gcc -Wall -Werror -o $(MOT) -c test/main.c
build/test/board_read_test.o:
	gcc -Wall -Werror -o $(BROT) -c test/board_read.c
build:
	mkdir build
build/scr:
	mkdir build/scr
build/test:
	mkdir build/test
.PHONY : clean test
clean: 
	rm -rf ignore/
	rm -rf build/ 
