#include "../inc/Board.hh"
//#include "../inc/WinCondition.hh"
#include "../inc/MinMax.hh"

int main()
{	
	unsigned int winningNumber, sizeOfBoard;
	char player1Sign, player2Sign;
	pair<int, pair<int, int> > resultOfMinMax;	
	cout << "Podaj rozmiar planszy: ";
	cin >> sizeOfBoard;
	while(sizeOfBoard <= 0 || sizeOfBoard > 50)
	{
		cout << "Nieprawidlowa wartosc. Wpisz ponownie: ";
		cin >> sizeOfBoard;
	}	

	Board plansza = Board(sizeOfBoard);
	
	cout << "Podaj ilosc w rzedzie, ktora powoduje wygrana: ";
	cin >> winningNumber;
	while(winningNumber <= 1 || winningNumber > sizeOfBoard)
	{
		cout << "Nieprawidlowa wartosc. Wpisz ponownie: ";
		cin >> winningNumber;
	}	
	WinCondition wygrana = WinCondition(winningNumber);

	cout << "Podaj znak gracza 1: ";
	cin >> player1Sign;
	Player gracz1 = Player(1, player1Sign);

	cout << "Podaj znak gracza 2: ";
	cin >> player2Sign;
	Player gracz2 = Player(2, player2Sign);

	int czy_wygrana = wygrana.Winner(plansza, gracz1, gracz2);
	unsigned int wiersz, kolumna, licznik = 1;
	cout << "Podawaj ruch jako: wiersz kolumna" << endl;
	plansza.displayBoard(gracz1, gracz2);

	while(czy_wygrana == -1)
	{
		if(licznik % 2 == 1)
		{
			cout << "Tura gracza 1. Wykonaj swoj ruch: ";
			cin >> wiersz >> kolumna;
			while(plansza.isMovePossible(wiersz - 1, kolumna - 1, gracz1) != true)
			{
				cout << "Nie mozna wykonac ruchu, wpisz ponownie: ";
				cin >> wiersz >> kolumna;
			}
			plansza.addMove(wiersz - 1, kolumna - 1, gracz1); 	
		}
		else
		{
			resultOfMinMax = MinMax(plansza, gracz1, gracz2, false, wygrana, 0);
			plansza.addMove(resultOfMinMax.second.first, resultOfMinMax.second.second, gracz2);
			
			/*
			cout << "Tura gracza 2. Wykonaj swoj ruch: ";
			cin >> wiersz >> kolumna;
			while(plansza.isMovePossible(wiersz - 1, kolumna - 1, gracz2) != true)
			{
				cout << "Nie mozna wykonac ruchu, wpisz ponownie: ";
				cin >> wiersz >> kolumna;
			}
			plansza.addMove(wiersz - 1, kolumna - 1, gracz2); */
	
		}
		
		plansza.displayBoard(gracz1, gracz2);
		licznik++;
		czy_wygrana = wygrana.Winner(plansza, gracz1, gracz2);
	}
	
	if(czy_wygrana == gracz1.playerID) 
	{
		cout << "WYGRACZA GRACZA 1"<<endl;
	}
	else 
	{
		if (czy_wygrana == gracz2.playerID) cout << "WYGRANA GRACZA 2" << endl;
		else cout << "REMIS" <<endl;
	}

	return 0;
}

