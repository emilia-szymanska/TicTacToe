#include "../inc/WinCondition.hh"

WinCondition::WinCondition(unsigned int winningNumber)
{
	this->winningNumber = winningNumber;
/*	
	this->rowSample = Matrix(1, winningNumber);
	for(unsigned int i = 0; i < this->winningNumber; i++) this->rowSample(0, i) = 1;
	
	this->columnSample = Matrix(winningNumber, 1);
	for(unsigned int i = 0; i < this->winningNumber; i++) 
	{
		this->rowSample(i, 0) = 1;
		//cout<<i<<endl;
	}	

	this->slashSample = Matrix(winningNumber, winningNumber);
	unsigned int j = winningNumber - 1;
	for(unsigned int i = 0; i < this->winningNumber; i++) 
	{
		this->rowSample(i, j) = 1;
		j--;
	}	

	this->backslashSample = Matrix(winningNumber, winningNumber);
	j = 0;
	for(unsigned int i = 0; i < this->winningNumber; i++) 
	{
		this->rowSample(i, j) = 1;
		j++;
	}	
*/
}

unsigned int WinCondition::Winner(Board gameBoard, Player player1, Player player2)
{
	unsigned int boardSize = gameBoard.returnSize();
	Matrix boardCopy = gameBoard.returnMatrixOfFields();
	
	int flagPlayer1 = 1, flagPlayer2 = 1;

	//horizontal
	for(unsigned int i = 0; i < boardSize; i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer1 = 1;
			for(unsigned int k = j; k < (this->winningNumber + j); k++)
			{
				if(boardCopy(i,k) != player1.playerID) 
				{
					flagPlayer1 = 0;
					break;
				}	
			}
			if (flagPlayer1 == 1) return player1.playerID;	
		}
	}
	
	for(unsigned int i = 0; i < boardSize; i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer2 = 1;
			for(unsigned int k = j; k < (this->winningNumber + j); k++)
			{
				if(boardCopy(i,k) != player2.playerID) 
				{
					flagPlayer2 = 0;
					break;
				}	
			}
			if (flagPlayer2 == 1) return player2.playerID;	
		}
	}
	
	//vertical
	for(unsigned int i = 0; i < boardSize; i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer1 = 1;
			for(unsigned int k = j; k < (this->winningNumber + j); k++)
			{
				if(boardCopy(k, i) != player1.playerID) 
				{
					flagPlayer1 = 0;
					break;
				}	
			}
			if (flagPlayer1 == 1) return player1.playerID;	
		}
	}
	
	for(unsigned int i = 0; i < boardSize; i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer2 = 1;
			for(unsigned int k = j; k < (this->winningNumber + j); k++)
			{
				if(boardCopy(k, i) != player2.playerID) 
				{
					flagPlayer2 = 0;
					break;
				}	
			}
			if (flagPlayer2 == 1) return player2.playerID;	
		}
	}

	return 0;
}
