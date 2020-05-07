#ifndef BOARD_HH
#define BOARD_HH
#include <vector>
#include <iostream>
using namespace std;

struct Player
{
	unsigned int playerID;
	char playerSign;
	Player(unsigned int playerID, char playerSign)
	{
		this->playerID = playerID;
		this->playerSign = playerSign;
	}	
};

struct Matrix
{
	unsigned int dimension;
	vector<unsigned int> V;
	
	Matrix(unsigned int dimension = 1)
	{
		this->dimension = dimension;
		this->V.resize(dimension*dimension, 0); 
	}

	unsigned int & operator () (unsigned int i, unsigned int j)
	{
		return V[i * this->dimension + j];
	}	
};

class Board
{
	unsigned int dimension;
	Matrix matrixOfFields;

	public:
		Board(unsigned int newDimension)
		{
			this->dimension = newDimension;
			this->matrixOfFields = Matrix(newDimension);
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
		void resetBoard();
};

#endif
