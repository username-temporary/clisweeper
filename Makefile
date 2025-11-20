

all: board_test

run:all
	./board_test
board.o:src/board.c
	gcc -c src/board.c
	
board_print.o:src/board_print.c
	gcc -c src/board_print.c

board_test: board.o board_print.o
	gcc -o board_test board.o board_print.o tests/board_test.c


clean : 
	rm *.o board_test
