#include "../inc/MinMax.hh"
#define MAX_DEPTH 2

pair< int, pair<int, int> > MinMax(Board & gameBoard, Player player1, Player player2, bool minOrMax, WinCondition condition, int depth)
{
	int MinMaxValue = -2;
	pair<int,int> move;
	unsigned int boardSize = gameBoard.returnSize();
	Matrix & fields = gameBoard.returnMatrixOfFields();
	int winner;
	int player1ID = player1.playerID;
	int player2ID = player2.playerID;
	int result = condition.Winner(gameBoard, player1, player2);
	pair <int, pair<int, int> > nextRecursion;
	if(result == 0)
	{
		winner = 0;
	}
	else
	{
		if(result == player1ID)
		{
			winner = 1;
		}
		else
		{
			if(result == player2ID) winner = -1;
			else winner = 2;
		}	
	}

	if(winner != 2)
	        return {winner, {-1, -1} };

	if(depth == MAX_DEPTH)
		return {0, {-1, -1}};

	for(unsigned int i = 0; i < boardSize; i++)
	{	
		for(unsigned int j = 0; j < boardSize; j++)
		{
			if(fields(i,j) == 0)
			{
				if(minOrMax)			//maximizing
				{
					gameBoard.addMove(i, j, player1);
					nextRecursion = MinMax(gameBoard, player1, player2, false, condition, depth+1);
					if(MinMaxValue == -2 or nextRecursion.first > MinMaxValue)
					{
						MinMaxValue = nextRecursion.first;
						move = {i,j};
					}
				}
				else				//minimizing
				{
					gameBoard.addMove(i, j, player2);
					nextRecursion = MinMax(gameBoard, player1, player2, true, condition, depth+1);
					if(MinMaxValue == -2 or nextRecursion.first < MinMaxValue)
					{
						MinMaxValue = nextRecursion.first;
						move = {i,j};
					}

				}
				gameBoard.removeMove(i,j);
			}
		}
	}

	return {MinMaxValue, move};	
}

