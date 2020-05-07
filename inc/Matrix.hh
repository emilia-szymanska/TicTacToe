#ifndef MATRIX_HH
#define MATRIX_HH
#include <vector>
using namespace std;

struct Matrix
{
	unsigned int rows;
	unsigned int columns;
	vector<unsigned int> V;
	
	Matrix(unsigned int rows = 1, unsigned int columns = 1)
	{
		this->rows = rows;
		this->columns = columns;
		this->V.resize(rows*columns, 0); 
	}

	unsigned int & operator () (unsigned int i, unsigned int j)
	{
		return V[i * this->columns + j];
	}	
};

#endif
