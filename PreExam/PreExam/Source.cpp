#include<iostream>
using namespace std;

int const MAX_SIZE = 10000;

void Print(int * a,int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;

	delete[] a;
}

int* Merge(int first[], int second[], int m, int n)
{
	int firstIndex = 0;
	int secondIndex = 0;

	int* result = new int[m + n];

	while (secondIndex + firstIndex < m + n )
	{
		if (first[firstIndex] > second[secondIndex] && secondIndex<n)
		{
			result[firstIndex + secondIndex] = second[secondIndex];
			secondIndex++;
		}
		else if(firstIndex<m)
		{
			result[firstIndex + secondIndex] = first[firstIndex];
			firstIndex++;
		}
		else
		{
			result[firstIndex + secondIndex] = second[secondIndex];
			secondIndex++;
		}
	}

	return result;
}


int main()
{
	int first[MAX_SIZE];
	int second[MAX_SIZE];

	int m, n;

	cin >> m;

	for (size_t i = 0; i < m; i++)
	{
		cin >> first[i];
	}

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> second[i];
	}

	Print(Merge(first, second, m, n),m+n);


	system("pause");

	return 0;
}