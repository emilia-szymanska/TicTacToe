#ifndef WINCONDITION_HH
#define WINCONDITION
#include "Board.hh"


class WinCondition
{
	unsigned int winningNumber;

	public:
		WinCondition(unsigned int winningNumber);
		int Winner(Board & gameBoard, Player player1, Player player2); 
};


#endif
