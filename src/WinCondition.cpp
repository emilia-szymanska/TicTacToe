#include "../inc/WinCondition.hh"

WinCondition::WinCondition(unsigned int winningNumber)
{
	this->winningNumber = winningNumber;
	
	this->rowSample = Matrix(1, winningNumber);
	for(unsigned int i = 0; i < this->winningNumber; i++) this->rowSample(0, i) = 1;
	
	this->columnSample = Matrix(winningNumber, 1);
	for(unsigned int i = 0; i < this->winningNumber; i++) this->rowSample(i, 0) = 1;

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

}

unsigned int WinCondition::Winner(Board gameBoard, Player player1, Player player2)
{
	unsigned int boardSize = Board.returnSize();
	Matrix boardCopy = Board.returnMatrixOfFields();

	for(unsigned int i = 0; i < boardSize; i++)
	{
		for(unsigned int j = 0; j < boardSize; j++)
		{

		}
	}
}	

