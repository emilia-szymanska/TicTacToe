tictactoe: obj obj/main.o obj/Board.o
	g++ -o tictactoe obj/main.o obj/Board.o

obj/main.o: src/main.cpp
	g++ -c -o obj/main.o src/main.cpp

obj/Board.o: src/Board.cpp inc/Board.hh
	g++ -c -o obj/Board.o src/Board.cpp 
