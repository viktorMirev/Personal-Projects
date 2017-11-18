/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 4
* @compiler VC
*
*/



#include<iostream>
using namespace std;

int main()
{
	int min;
	int number;
	cout << "Enter the seqence" << endl;
	cin >> number;
	min = number;

	while (number != 0)
	{
		min = (number < min) ? number : min;

		cin >> number;
	}

	cout << min << endl;

	system("pause");
	return 0;
}