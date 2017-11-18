/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 3
* @compiler VC
*
*/



#include<iostream>
using namespace std;

int main()
{
	long numOfsecs;
	cout << "Enter the seconds" << endl;
	cin >> numOfsecs;
	if (numOfsecs>24 * 3600)
	{
		cout << "WRONG! no more than 24 hours" << endl;
		system("pause");
		return 0;
	}

	int minutes = (numOfsecs % 3600) / 60;
	int hours = numOfsecs / 3600;

	if (hours < 10)
	{
		cout << "0" << hours << ":";
	}
	else
	{
		cout << hours << ":";
	}

	if (minutes < 10)
	{
		cout << "0" << minutes << endl;
	}
	else
	{
		cout << minutes << endl;
	}


	system("pause");
	return 0;
}