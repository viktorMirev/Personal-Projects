#include<iostream>

using namespace std;

const int TURN_VAR = -1;

struct matrixPair
{
	int value;
	bool isEdge = false;
};

void PrintIt(matrixPair matrix[][100], int m,int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout<<matrix[i][j].value<< " ";
		}
		cout << endl;
	}
}

void SpiralIt(matrixPair matrix[][100], int m,int n)
{
	int count = m*n;
	int currDir = 1;
	int ittI = 1;
	int ittJ = 1;
	int currItt = 1;
	int i = 0;
	int j = 0;
	while (currItt <= count)
	{
		matrix[i][j].value = currItt;
		matrix[i][j].isEdge = true;
		if (currItt == count) break;
		if (currDir == 1)
		{//itterate J
			if (j + ittJ < m && j+ittJ>=0 &&matrix[i][j + ittJ].isEdge == false)
			{
				j += ittJ;
			}
			else
			{
				ittJ *= TURN_VAR;
				currDir *= TURN_VAR;
				continue;
			}
		}
		else
		{//itterate I
			if (i + ittI < n && i+ittI>=0 && matrix[i+ittI][j].isEdge == false)
			{
				i += ittI;
			}
			else
			{
				ittI *= TURN_VAR;
				currDir *= TURN_VAR;
				continue;
			}
		}

		currItt++;
		

	}
}

int main()
{
	int m, n;
	matrixPair matrix[100][100];
	cout << "Type the dimentions" << endl;
	cin >> m;
	cin >> n;
	SpiralIt(matrix, m,n);
	PrintIt(matrix, m,n);
	system("pause");
	return 0;
}