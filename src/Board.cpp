#include "../inc/Board.hh"

void Board::displayBoard(Player playerName1, Player playerName2)
{
	for(unsigned int i = 0; i <= this->returnSize(); i++)
	{
		for(unsigned int j = 0; j <= this->returnSize(); j++)
		{
			if(i == 0) 							//displaying a row of numbers
			{
				if(j == 0) cout << "  " << j+1;
				else if(j != this->returnSize()) cout << " " << j+1;
			}
			else 
			{
				if(j == 0) 
				{
					cout << i << " ";				//displaying the number of the line
				}
				else 
				{
					if(this->matrixOfFields(i-1,j-1) == playerName1.playerID) 
					{
						cout << playerName1.playerSign << " ";
					}
					else 
					{
						if(this->matrixOfFields(i-1,j-1) == playerName2.playerID) cout << playerName2.playerSign << " ";
						else cout << "_ ";
					}	
				}
			}
		}
		cout << endl;
	}
}


void Board::addMove(unsigned int i, unsigned int j, Player playerName)
{
	if(this->matrixOfFields(i,j) == 0) this->matrixOfFields(i,j) = playerName.playerID;
	else cout << "This field is already occupied"<<endl;
}


void Board::resetBoard()
{
	for(unsigned int i = 0; i < this->returnSize(); i++)
		for(unsigned int j = 0; j < this->returnSize(); j++)
			this->matrixOfFields(i, j) = 0;
}
