//the user gives the 2 dimentional array
//there is an integer in each cell representing the number
//of points in it
//the program should calculate the maximum score
//if the start is at the [0][0] and the finish is in [n][n]
//moves allowed only rightwards and downwards

#include<iostream>
using namespace std;


int main()
{
	int n; //dimention
	
	cout << "Enter the dimention of the matrix" << endl;
	cin >> n;
	int a[100][100]; // matrix
	cout << "Enter the elements (n x n)" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	

	//calculating

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int up = 0;
			int left = 0;
			if (i - 1 >= 0)
			{
				up += a[i - 1][j];
			}
			if (j - 1 >= 0)
			{
				left += a[i][j - 1];
			}

			if (left > up)
			{
				a[i][j] += left;
			}

			else
			{
				a[i][j] += up;
			}
		}
	}

	cout << "Highest possible score: " << a[n - 1][n - 1] << endl;
	system("pause");
	return 0;
}