/*
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 5
* @compiler VC
*
*/



#include<iostream>
using namespace std;

int main()
{
	int n;
	int digits = 0;
	int firstDigit = 0;
	int lastDigit = 0;
	int middleSection = 0;
	bool isNegative = false;

	cout << "Enter an integer" << endl;
	cin >> n;

	//if the number has only one digit we dont need to 
	//swap the first and the last
	if (n > -10 && n < 10)
	{
		cout << n << endl;
		system("pause");
		return 0;
	}
	//we check if it is negative becasue of the log
	if (n < 0)
	{
		isNegative = true;
		n = abs(n);
	}

	//getting the number of the digits
	digits = log10(n) - 1;

	lastDigit = n % 10;
	n /= 10;

	int magnitute = pow(10, digits);
	firstDigit = n / magnitute;
	middleSection = n % magnitute;

	if (isNegative)
	{
		lastDigit *= -1;
	}

	if (middleSection == 0)
	{
		cout << lastDigit * 10 + firstDigit << endl;
		system("pause");
		return 0;
	}

	cout << lastDigit << middleSection * 10 + firstDigit << endl;
	system("pause");
	return 0;

}
