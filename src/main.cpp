#include "../inc/Board.hh"
#include "../inc/WinCondition.hh"

int main()
{	

	/*int tab[5][5];
	for(int i = 0; i<5; i++)
		for(int j=0; j<5; j++)
			tab[i][j]=0;
	tab[3][2]=2;
	tab[4][4]=3; 

	for(unsigned int i = 0; i <= 5; i++)
	{
		for(unsigned int j = 0; j <= 5; j++)
		{
			if(i==0) 
			{
				if(j==0) cout<<"  "<<j+1;
				else if(j!=5) cout << " " << j+1;
			}
			else 
			{
				if(j==0) cout<<i<<" ";
				else cout<<tab[i-1][j-1]<<" ";
			}
		}
		cout << endl;
	}*/

	Player ja = Player(1, 'X');
	Player ty = Player(2, 'Y');
	WinCondition wygranko = WinCondition(3);
	Board plansza = Board(5);
/*	plansza.addMove(1, 0, ja);
	plansza.addMove(2, 1, ja);
	plansza.addMove(3, 2, ja);
	
	cout<<wygranko.Winner(plansza, ja, ty)<<endl;
	*/
//	plansza.addMove(1, 2, ty);
	plansza.addMove(0, 2, ty);
	plansza.addMove(1, 1, ty);
	plansza.addMove(2, 0, ty);

	plansza.displayBoard(ja, ty);
	cout<<wygranko.Winner(plansza, ja, ty)<<endl;
	return 0;
}

