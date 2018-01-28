#include<iostream>
#include<iomanip>
using namespace std;

int const LENGTH = 80;
int const HEIGHT = 25;

void Print(int length, int height,char symbol)
{
	int leftOffSet = (LENGTH - length) / 2;
	int topOffSet = (HEIGHT - height) / 2;

	//printing top
	for (size_t i = 0; i < topOffSet; i++)
	{
		cout << endl;
	}

	//printing the imp part
	for (size_t i = 0; i < height; i++)
	{
		//left offset
		cout << setw(leftOffSet);

		for (size_t i = 0; i < length; i++)
		{
			cout << symbol;
		}
		cout << endl;
	}
}

int main()
{
	int m, n;
	cin >> m >> n;
	char symbol;
	cin >> symbol;

	Print(m, n, symbol);
	system("pause");
}