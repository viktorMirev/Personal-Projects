#include<iostream>
using namespace std;


int const MAX = 100;


int Sum(int matrix[][MAX],int n)
{
	int sum=0;
	for (size_t i = 0; i < n-1; i++)
	{
		for (size_t j = i+1; j < n; j++)
		{
			sum += matrix[i][j];
		}
		
	}
	return sum;
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

	cout << Sum(matrix,n)<<endl;
	system("pause");
	return 0;
}