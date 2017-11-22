//the user gives the 2 dimentional array
//there is an integer in each cell representing the number
//of points in it
//the program should calculate the maximum score
//if the start is at the [0][0] and the finish is in [n][n]
//moves allowed only rightwards and downwards

#include<iostream>
using namespace std;
struct Cell
{
	int i = 0;
	int j = 0;
	int points;
};

Cell BiggestSum(Cell a[][100], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int up = 0;
			int left = 0;
			if (i - 1 >= 0)
			{
				up += a[i - 1][j].points;
			}
			if (j - 1 >= 0)
			{
				left += a[i][j - 1].points;
			}

			if (left > up)
			{
				a[i][j].points += left;
				a[i][j].i = i;
				a[i][j].j = j - 1;
			}

			else
			{
				a[i][j].points += up;
				a[i][j].i = i - 1;
				a[i][j].j = j;
			}
		}
	}
	return a[n - 1][n - 1];
}
void InputHandler(Cell a[][100], int *n)
{
	cout << "Enter the dimention of the matrix" << endl;
	cin >> *n;
	cout << "Enter the elements (n x n)" << endl;
	for (int i = 0; i < *n; i++)
	{
		for (int j = 0; j < *n; j++)
		{
			cin >> a[i][j].points;
		}
	}
}
void PrintRoute(Cell a[][100]  ,int n)
{
	cout << "Route: " << endl;
	int i=n-1;
	int j=n-1;
	cout << i << " " << j << endl;
	while (i != 0 || j != 0)
	{
		int helper;
		helper = a[i][j].i;
		j = a[i][j].j;
		i = helper;
		cout << i << " " << j << endl;
	}
}

int main()
{
	//dimention
	int n; 
	//matrix
	Cell a[100][100];

	InputHandler(a, &n);
	Cell last = BiggestSum(a, n);
	cout << "Biggest Sum = "<<last.points<< endl;
	
	PrintRoute(a, n);
	system("pause");
	return 0;
}