#include "../inc/WinCondition.hh"

WinCondition::WinCondition(unsigned int winningNumber)
{
	this->winningNumber = winningNumber;

}

int WinCondition::Winner(Board & gameBoard, Player player1, Player player2)
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
//	cerr<<"horizontal"<<endl;
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
	
//	cerr<<"vertical"<<endl;
	//backslash
	unsigned int l;
	for(unsigned int i = 0; i < (boardSize - this->winningNumber); i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer1 = 1;
			l = i;
			for(unsigned int k = j; k < (this->winningNumber + j); k++)
			{
				if(boardCopy(l,k) != player1.playerID) 
				{
					flagPlayer1 = 0;
					break;
				}
				l++;	
			}
			if (flagPlayer1 == 1) return player1.playerID;	
		}
	}
	
	for(unsigned int i = 0; i < (boardSize - this->winningNumber); i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer2 = 1;
			l = i;
			for(unsigned int k = j; k < (this->winningNumber + j); k++)
			{
				if(boardCopy(l,k) != player2.playerID) 
				{
					flagPlayer2 = 0;
					break;
				}
				l++;	
			}
			if (flagPlayer2 == 1) return player2.playerID;	
		}
	}
	
//	cerr<<"backslash"<<endl;
	//slash
	for(unsigned int i = 0; i < (boardSize - this->winningNumber); i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer1 = 1;
			l = i;
			for(unsigned int k = j + (this->winningNumber) - 1; k < boardSize; k--)
			{
				if(boardCopy(l,k) != player1.playerID) 
				{
					flagPlayer1 = 0;
					break;
				}
				l++;	
			}
			if (flagPlayer1 == 1) return player1.playerID;	
		}
	}
	
	for(unsigned int i = 0; i < (boardSize - this->winningNumber); i++)
	{
		for(unsigned int j = 0; j <= (boardSize - this->winningNumber); j++)
		{
			flagPlayer2 = 1;
			l = i;
			for(unsigned int k = j + (this->winningNumber) - 1; k < boardSize; k--)
			{
				if(boardCopy(l,k) != player2.playerID) 
				{
					flagPlayer2 = 0;
					break;
				}
				l++;	
			}
			if (flagPlayer2 == 1) return player2.playerID;	
		}
	}
	
//	cout<<"slash"<<endl;
	//not a draw
	for(unsigned int i = 0; i < boardSize; i++)
	{
		for(unsigned int j = 0; j < boardSize; j++)
		{
			if (boardCopy(i,j) == 0) return -1;	
		}
	}
//cout<<"nobody"<<endl;
	//draw
//	cout<<"draw"<<endl;
	return 0;
}
