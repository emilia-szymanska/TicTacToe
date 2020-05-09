#include "../inc/GameManagement.hh"

void GameManagement()
{	
	unsigned int winningNumber, sizeOfBoard;
	char AISign, userSign;
	pair<int, pair<int, int> > resultOfMinMax;	
	unsigned int row, column, counter = 0;
	
	cout << "Size of the board: ";
	cin >> sizeOfBoard;
	while(sizeOfBoard < 3 || sizeOfBoard > 50)
	{
		cout << "Incorrect value. Type again: ";
		cin >> sizeOfBoard;
	}	

	Board board = Board(sizeOfBoard);
	
	cout << "Number of elements in a row to win: ";
	cin >> winningNumber;
	while(winningNumber <= 1 || winningNumber > sizeOfBoard)
	{
		cout << "Incorrect value. Type again: ";
		cin >> winningNumber;
	}	

	WinCondition win = WinCondition(winningNumber);

	cout << "Type your sign: ";
	cin >> userSign;
	Player user = Player(1, userSign);

	cout << "Type the sign of the AI: ";
	cin >> AISign;
	Player AI = Player(2, AISign);
	
	cout << "Who should start: you (type: 1) or AI (type 2)? ";
	cin >> counter;
	while(counter != 1 and counter != 2)
	{
		cout << "Incorrect value. Type again: ";
		cin >> counter;
	}

	int if_victory = win.Winner(board, user, AI);
	cout << "Type your move as: row column" << endl;
	board.displayBoard(user, AI);

	while(if_victory == -1)
	{
		if(counter % 2 == 1)
		{
			cout << "Your turn. Make your move: ";
			cin >> row >> column;
			while(board.isMovePossible(row - 1, column - 1, user) != true)
			{
				cout << "You cannot make that move, type again: ";
				cin >> row >> column;
			}
			board.addMove(row - 1, column - 1, user); 	
		}
		else
		{
			cout << "AI's turn" <<endl;
			resultOfMinMax = MinMax(board, user, AI, false, win, 0);
			board.addMove(resultOfMinMax.second.first, resultOfMinMax.second.second, AI);
			
	
		}
		
		board.displayBoard(user, AI);
		counter++;
		if_victory = win.Winner(board, user, AI);
	}
	
	if(if_victory == user.playerID) 
	{
		cout << "YOU WON! :)"<<endl;
	}
	else 
	{
		if (if_victory == AI.playerID) cout << "AI WON! :(" << endl;
		else cout << "DRAW" <<endl;
	}
}	

