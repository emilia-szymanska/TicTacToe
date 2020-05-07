//#include <iostream>
//using namespace std;
//#include "Board.cpp"
#include "../inc/Board.hh"

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
	Board plansza = Board(5);
	cout<<"Wymiar "<<plansza.returnSize()<<endl;
	plansza.addMove(3, 2, ja);
	plansza.addMove(2, 3, ty);
	plansza.addMove(2, 3, ja);
	plansza.displayBoard(ja, ty);
	return 0;
}

