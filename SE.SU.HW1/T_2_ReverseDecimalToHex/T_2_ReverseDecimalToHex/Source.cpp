/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 2
* @compiler VC
*
*/



#include<iostream>
using namespace std;

//prints the current HEX digit
void Print(int n)
{
	if (n < 10)
	{
		cout << n;
	}
	else
	{
		char symbol = 'A';
		symbol += (n - 10);
		cout << symbol;
	}
}
//recursively finds the hex number in correct order
void Hex(int num)
{
	if (num != 0)
	{
		Hex(num / 16);
		Print(num % 16);
	}
}
//Reverses the given number
int Reverse(int number)
{
	int reversed = 0;
	int itt = 0;
	while (number != 0)
	{
		reversed *= 10;
		reversed += number % 10;
		number /= 10;
	}

	return reversed;
}

int main()
{
	int n;
	cout << "Type a positive integer" << endl;
	cin >> n;
	while (n < 0)
	{
		cout << "error" << endl;
		cout << "Type a positive integer" << endl;
		cin >> n;
	}
	//if the number is 1 digit we dont have to reverse it and also 
	//it is the same in HEX
	if (n < 10)
	{
		cout << n << endl;
		system("pause");
		return 0;
	}
	n = Reverse(n);

	Hex(n);
	cout << endl;
	system("pause");
	return 0;
}