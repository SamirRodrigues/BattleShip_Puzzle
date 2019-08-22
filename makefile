Battleship: ship_generator.o puzzle_generator.o board_generator.o main.o
	g++ -Wall -std=c++11 ship_generator.o puzzle_generator.o  board_generator.o main.o -o BPG -lm -I include/
	-rm *.o
ship_generator.o:
	g++ -std=c++11 -o ship_generator.o -c src/ship_generator.cpp
puzzle_generator.o:
	g++ -std=c++11 -o puzzle_generator.o -c src/puzzle_generator.cpp
board_generator.o:
	g++ -std=c++11 -o board_generator.o -c src/board_generator.cpp
main.o:
	g++ -std=c++11 -o main.o -c src/main.cpp
