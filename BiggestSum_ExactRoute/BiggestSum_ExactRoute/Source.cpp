//the user gives the 2 dimentional array
//there is an integer in each cell representing the number
//of points in it
//the program should calculate the maximum score
//if the start is at the [0][0] and the finish is in [n][n]
//moves allowed only rightwards and downwards

/*test
0 0 0 0 1
0 1 0 0 1
1 0 0 1 0
1 0 0 1 0
0 0 0 0 0
3
*/

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
			//in case one is not an option but both are 0 so if j is 0 it is going 
			//to be -1 now which is bad 
			//we make excuse for 0 0 because it has 
			//no element before it(if we itterate it the points of it will be -=1)
			if (i == 0 && j == 0)
			{
				//the only one special 
				continue;
			}

			//now 0 will be the only one who is the real predecessor
			//(this is in case you have for example no element on your up
			//but the one on your left is 0)

			int up = -1;
			int left = -1;
			if (i - 1 >= 0)
			{
				up += (a[i - 1][j].points+1);
			}
			if (j - 1 >= 0)
			{
				left += (a[i][j - 1].points+1);
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

void RecursiveRoute(Cell a[][100], int i, int j, char vis[][100] )
{
	if (i == 0 && j == 0)
	{
		return;
	}
	int helper;
	helper = a[i][j].i;
	j = a[i][j].j;
	i = helper;
	RecursiveRoute(a, i, j,vis);
	cout<<"[" << i << " : " << j<<"]" << endl;
	vis[i][j] = '*';
}


void PrintRoute(Cell a[][100], int n)
{
	//visualisation of the route
	char vis[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			vis[i][j] = '0';
		}
	}

	cout << endl;
	cout << "Route (Coordinates) " << endl;
	int i = n - 1;
	int j = n - 1;
	RecursiveRoute(a, i, j,vis);

	cout << endl;
	cout << "Route (Visualisation) " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << vis[i][j]<<" ";
		}
		cout << endl;
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
	cout << "Biggest Sum = " << last.points << endl;

	PrintRoute(a, n);
	system("pause");
	return 0;
}