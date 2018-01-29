#include<iostream>
using namespace std;


int const MAX = 100;


int** Sum(int matrix[][MAX], int n)
{
	int** t = new int*[n];
	for (size_t i = 0; i < n; i++)
	{
		t[i] = new int[MAX];
	}


	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			t[j][i] = matrix[i][j];
		}

	}
	return t;
}

void Print(int** t,int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cout << t[i][j]<<" ";
		}
		cout << endl;
	}

	//DELETE
	for (size_t i = 0; i < n; i++)
	{
		delete[] t[n];
	}
	delete[] t;
}

int main()
{
	int matrix[MAX][MAX];

	int n;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	int ** t = Sum(matrix, n);

	Print(t,n);

	system("pause");
	return 0;
}
