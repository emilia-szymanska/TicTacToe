tictactoe: obj obj/main.o obj/Board.o obj/WinCondition.o
	g++ -o tictactoe obj/main.o obj/Board.o obj/WinCondition.o

obj/main.o: src/main.cpp
	g++ -c -o obj/main.o src/main.cpp

obj/WinCondition.o: src/WinCondition.cpp inc/WinCondition.hh inc/Board.hh
	g++ -c -o obj/WinCondition.o src/WinCondition.cpp 

obj/Board.o: src/Board.cpp inc/Board.hh inc/Player.hh inc/Matrix.hh
	g++ -c -o obj/Board.o src/Board.cpp 
