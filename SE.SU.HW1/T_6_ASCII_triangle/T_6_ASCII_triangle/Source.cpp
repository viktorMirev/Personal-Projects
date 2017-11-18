/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 6
* @compiler VC
*
*/



#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
	char symbol;
	int height;
	cout << "enter the ASCII" << endl;
	cin >> symbol;
	cout << "enter the height(no more than 25)" << endl;
	cin >> height;
	if (height > 25)
	{
		cout << "wrong!" << endl;
		return 0;
	}

	for (int i = 0; i < height; i++)
	{
		cout << setw(height - i); // we set the offset using setw to place a number of spaces

		for (int j = 0; j < 1 + 2 * i; j++)
		{
			if (j % 2 == 1) cout << " ";
			else cout << symbol;
		}
		cout << endl; // end of the current line
	}
	system("pause");
	return 0;
}