#include<iostream>

using namespace std;

//FUNCTIONS
void Delete(int ** m, int n);
int ** Multiply(int ** matrx1, int ** matrx2, int m, int n, int q);
void Print(int ** matrx, int m, int n);
bool HandleInput(int *** matrx1, int *** matrx2, int * m, int * n, int * p, int * q);
//

int main()
{

	int ** matrx1 = 0;
	int ** matrx2 = 0;

	//number of columns & rolls of the first;
	int m;
	int n;

	//number of columns & rolls of the second
	int p;
	int q;

	//the multiplied matrix
	int ** result;

	//we use & because the functions need a pointer to a pointer to an array of pointers
	if (HandleInput(&matrx1, &matrx2, &m, &n, &p, &q))
	{
		result = Multiply(matrx1, matrx2, m, n, q);
	}
	else
	{
		return main();
	}

	Print(result, m, q);
	Delete(result, m);

	system("pause");
	return 0;

}

void Delete(int ** m, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		delete[] m[i];
	}
	delete[] m;
}

int ** Multiply(int ** matrx1, int ** matrx2, int m, int n , int q)
{
	int ** result = new int*[m];

	for (size_t i = 0; i < m; i++)
	{
		result[i] = new int[q];
	}

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < q; j++)
		{
			int currSum = 0;
			for (size_t k= 0; k < n; k++)
			{
				currSum += matrx1[i][k] * matrx2[k][j];
			}
			result[i][j] = currSum;
		}
	}

	//deal with the memory leak
	Delete(matrx1, m);
	Delete(matrx2, n);


	return result;
}

void Print(int ** matrx, int m, int n)
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << matrx[i][j]<<" ";
		}
		cout << endl;
	}
}

/*
the basic idea is that when we have a pointer
to sth & we want to make it 
pt = new ... 
we change the pointer locally 
so if we want t change int **
we need a pointer to it 
so we change the value which the int *** points
*/

bool HandleInput(int *** matrx1, int *** matrx2,int * m, int * n, int * p, int * q)
{
	cout << "Insert the dimentions of the two matrices" << endl;
	cin >> *m >> *n >> *p >> *q;
	if (*p != *n)
	{
		cout << endl << "The second dimention of the first" << endl << "should be the same as the first dimention of the second" << endl << "notherwise it is not defined!" << endl;
		return false;
	}
	cout << endl;

	
	*matrx1 = new int*[*m];
	for (size_t i = 0; i < *m; i++)
	{
		(*matrx1)[i] = new int[*n];
	}

	
	*matrx2 = new int*[*p];
	for (size_t i = 0; i < *p; i++)
	{
		(*matrx2)[i] = new int[*q];
	}


	cout << "Enter the first matrix\n" << endl;
	for (size_t i = 0; i < *m; i++)
	{
		for (size_t j = 0; j < *n; j++)
		{
			cin >> (*matrx1)[i][j];
		}
	}
	cout << endl;

	cout << "Enter the second matrix\n" << endl;
	for (size_t i = 0; i < *p; i++)
	{
		for (size_t j = 0; j < *q; j++)
		{
			cin >> (*matrx2)[i][j];
		}
	}
	cout << endl;
	return true;
}

