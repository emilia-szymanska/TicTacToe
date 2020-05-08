#ifndef BOARD_HH
#define BOARD_HH
#include "Matrix.hh"
#include "Player.hh"
#include <iostream>
using namespace std;


class Board
{
	unsigned int dimension;
	Matrix matrixOfFields;

	public:
		Board(unsigned int newDimension)
		{
			this->dimension = newDimension;
			this->matrixOfFields = Matrix(newDimension, newDimension);
		}

		Matrix returnMatrixOfFields()
		{
			return this->matrixOfFields;
		}	
		unsigned int returnSize()
		{
			return this->dimension; 
		}

		void displayBoard(Player playerName1, Player playerName2);
		void addMove(unsigned int i, unsigned int j, Player playerName);
		bool isMovePossible(unsigned int i, unsigned int j, Player playerName);
		void resetBoard();
};

#endif
