#include<iostream>

using namespace std;

int main()
{
	int first;
	int second;
	cout << "Enter the first integer" << endl;
	cin >> first;
	cout << "Enter the second integer" << endl;
	cin >> second;

	first ^= second;
	second ^= first;
	first ^= second;
	cout << "First = " << first << endl;
	cout << "Second = " << second << endl;

	system("pause");

	return 0;
}