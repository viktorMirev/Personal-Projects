/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Viktor Mirev
* @idnumber 62231
* @task 3
* @compiler VC
*
*/



#include<iostream>

using namespace std;

char const MAX_INT_AS_STRING[11] = { "4294967296" };
char const MIN_INT_AS_STRING[11] = { "4294967296" };
int const INT_MAX_NUMBER_OF_DIGITS = 10;

//functions
bool IsGreaterThan(char first[100], char const second[100]);
int InputHandle(char number[100]);
int DigitHandle(char number[100], int length, int digits[10]);



int main()
{
	char number[100];
	int digits[10];

	//default 0
	for (int i = 0; i < 10; i++)
	{
		digits[i] = 0;
	}

	int length = InputHandle(number);
	//input varification
	if (length == -1)
	{
		cout << "-1" << endl;
		//	system("pause");
		return 0;
	}


	int maxNumber = DigitHandle(number, length, digits);

	for (int i = 0; i < 10; i++)
	{
		if (digits[i] == maxNumber) cout << i << "-->" << maxNumber << endl;
	}

	//system("pause");
	return 0;

}

bool IsGreaterThan(char first[100], char const second[100])
{
	for (size_t i = 0; i < 10; i++)
	{
		if (first[i] == second[i]) continue;

		if (first[i] > second[i]) return true;

		return false;
	}
	return false;
}

int InputHandle(char number[100])
{
	bool IsNegative = false;

	char currSymbol = getchar();
	if (currSymbol == '-')
	{
		IsNegative = true;
		currSymbol = getchar();
	}
	
	int length = 0;
	while (currSymbol != '\n' && currSymbol != '\r')
	{
		number[length] = currSymbol;
		length++;
		currSymbol = getchar();
	}

	int numberOFDigits = length;

	if (numberOFDigits > INT_MAX_NUMBER_OF_DIGITS)
	{
		return -1;
	}

	if (numberOFDigits == INT_MAX_NUMBER_OF_DIGITS)
	{
		if (IsNegative)
		{
			if (IsGreaterThan(number,MIN_INT_AS_STRING)) return -1;
		}
		else
		{
			if (IsGreaterThan(number,MAX_INT_AS_STRING)) return -1;
		}
	}
	return length;
	
	
}

int DigitHandle(char number[100],int length, int digits[10])
{
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		int index = number[i] - '0';
		digits[index]++;
		if (max < digits[index]) max = digits[index];
	}
	return max;
}
