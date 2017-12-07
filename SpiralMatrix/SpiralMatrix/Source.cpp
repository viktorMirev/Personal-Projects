#include<iostream>
#include<iomanip>
using namespace std;

const int TURN_VAR = -1;
const int CELL_WIDTH = 5;

struct matrixPair
{
	int value;
	bool isEdge = false;
};


void InputHandler(int *lenght, int *height, int *rightOrLeft);
void SpiralIt(matrixPair matrix[][100], int m, int n, int rightOrLeft);
void PrintIt(matrixPair matrix[][100], int m, int n);


void InputHandler(int *lenght,int *height,int *rightOrLeft)
{
	cout << "Insert the dimentions" << endl;
	cin >> *lenght;
	cin >> *height;
	cout << "Insert 1 if you want only right turns or -1 for left turns" << endl;
	cin >> *rightOrLeft;
}

void PrintIt(matrixPair matrix[][100], int m,int n)
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout<< setw(CELL_WIDTH) <<matrix[i][j].value;
		}
		cout << endl;
	}
}

void SpiralIt(matrixPair matrix[][100], int m,int n,int rightOrLeft)
{
	int count = m*n;
	
	//says if we itterate j or i
	int currItt = rightOrLeft;
	//direction of i
	int ittI = 1;
	//direction of j
	int ittJ = 1;
	//the current cell
	int currCount= 1;
	int i = 0;
	int j = 0;
	while (true)
	{
		matrix[i][j].value = currCount;
		matrix[i][j].isEdge = true;

		if (currCount >= count) break;

		
		///label
		if (currItt == 1)
		{//currently itterating J
		 //check if it borders the border of the matrix or a cell which was already passed
			if (j + ittJ >= m || j + ittJ < 0 || matrix[i][j + ittJ].isEdge == true)
			{
				//change the variable which is itterated 
				//change the way the prev variable was itterated (change direction)
				ittJ *= TURN_VAR;
				currItt *= TURN_VAR;
			}
		}
		else
		{
			//currently itterating I
			//check if it borders the border of the matrix or a cell which was already passed
			if (i + ittI >= n || i + ittI < 0 || matrix[i+ittI][j].isEdge == true)
			{
				//change the variable which is itterated 
				//change the way the prev variable was itterated (change direction)
				ittI *= TURN_VAR;
				currItt *= TURN_VAR;
			}
		}

		//if the currItt == 1 it is J which is itterated now
		//so the number which we have to add will be 0 
		//if the currItt == -1 it is I which is itterated now
		//so the number which we have to add is just ittI
		i += (currItt - 1) / -2 * ittI;

		//if the currItt == -1 it is I which is itterated now
		//so the number which we have to add will be 0 
		//if the currItt == 1 it is J which is itterated now
		//so the number which we have to add is just ittJ
		j += (currItt + 1) / 2  * ittJ;
		
		//we have 2 additional calculations but 
		//we save itterations where we have at least 2 IFs and 
		//we assign again the matrix[i][j] (with the old method)


		//first implementation (some additional loops)
		//if (currItt == 1)
		//{//itterate J
		//	//check if it borders the border of the matrix or a cell which was already passed
		//	if (j + ittJ < m && j+ittJ>=0 &&matrix[i][j + ittJ].isEdge == false)
		//	{
		//		j += ittJ;
		//	}
		//	else
		//	{
		//		//change the variable which is itterated 
		//		//change the way the prev variable was itterated (change direction)
		//		ittJ *= TURN_VAR;
		//		currItt *= TURN_VAR;
		//		continue;
		//	}
		//}
		//else
		//{//itterate I
		//	//check if it borders the border of the matrix or a cell which was already passed
		//	if (i + ittI < n && i+ittI>=0 && matrix[i+ittI][j].isEdge == false)
		//	{
		//		i += ittI;
		//	}
		//	else
		//	{
		//		//change the variable which is itterated 
		//		//change the way the prev variable was itterated (change direction)
		//		ittI *= TURN_VAR;
		//		currItt *= TURN_VAR;
		//		continue;
		//	}
		//}

		currCount++;
		

	}
}

int main()
{
	
	int lenght, height,rightOrLeft;
	matrixPair matrix[100][100];

	InputHandler(&lenght, &height, &rightOrLeft);
	SpiralIt(matrix, lenght,height,rightOrLeft);
	PrintIt(matrix, lenght,height);

	system("pause");
	return 0;
}