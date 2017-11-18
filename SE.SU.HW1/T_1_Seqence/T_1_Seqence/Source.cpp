/*
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 1
* @compiler VC
*
*/



#include<iostream>
using namespace std;

int main()
{
	int answer;
	int curr;
	int prev;
	cout << "enter the seqence" << endl;

	cin >> prev;
	if (prev <= 0)
	{
		cout << "there is no seqence" << endl;
		system("pause");
		return 0;
	}
	cin >> curr;

	if (curr > 0)
	{
		if (prev == curr)
		{
			cout << "undefined" << endl;
			return 0;
		}
		if (prev > curr)
		{
			answer = -1;
		}
		if (prev < curr)
		{
			answer = 1;
		}
	}
	else
	{
		cout << "there is no seqence" << endl;
		system("pause");
		return 0;
	}


	while (curr>0)
	{
		if (answer == 1)
		{
			if (prev == curr || prev > curr)
			{
				cout << "undefined" << endl;
				system("pause");
				return 0;
			}
		}
		else
		{
			if (prev == curr || prev < curr)
			{
				cout << "undefined" << endl;
				system("pause");
				return 0;
			}
		}


		prev = curr;
		cin >> curr;
	}

	if (answer == 1)
	{
		cout << "increasing" << endl;
	}
	else
	{
		cout << "decreasing" << endl;
	}


	system("pause");
	return 0;
}