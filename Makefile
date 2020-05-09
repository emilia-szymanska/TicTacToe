tictactoe: obj obj/main.o obj/Board.o obj/WinCondition.o obj/MinMax.o
	g++ -g -o tictactoe obj/main.o obj/Board.o obj/WinCondition.o obj/MinMax.o

obj/main.o: src/main.cpp
	g++ -g -c -o obj/main.o src/main.cpp

obj/MinMax.o: src/MinMax.cpp inc/MinMax.hh inc/WinCondition.hh
	g++ -g -c -o obj/MinMax.o src/MinMax.cpp 

obj/WinCondition.o: src/WinCondition.cpp inc/WinCondition.hh inc/Board.hh
	g++ -g -c -o obj/WinCondition.o src/WinCondition.cpp 

obj/Board.o: src/Board.cpp inc/Board.hh inc/Player.hh inc/Matrix.hh
	g++ -g -c -o obj/Board.o src/Board.cpp 
