#include<iostream>
#include<string>

using namespace std;

string const MAX_INT_AS_STRING = "2147483647";
string const MIN_INT_AS_STRING = "2147483648";
int const INT_MAX_NUMBER_OF_DIGITS = 10;

int InputHandle(string * number)
{
	cin >> *number;
	bool IsNegative = false;
	if(number->at(0) == '-')
	{
		*number = number->substr(1);
		IsNegative = true;
	}
	int numberOFDigits = number->length();

	if (numberOFDigits > INT_MAX_NUMBER_OF_DIGITS)
	{
		return -1;
	}

	if (numberOFDigits == INT_MAX_NUMBER_OF_DIGITS)
	{
		if (IsNegative)
		{
			if (*number > MIN_INT_AS_STRING) return -1;
		}
		else
		{
			if (*number > MAX_INT_AS_STRING) return -1;
		}
	}
	return 1;
	
	
}

int DigitHandle(string number, int digits[10])
{
	int length = number.length();
	int max = 0;
	for (int i = 0; i < length; i++)
	{
		int index = number[i] - '0';
		digits[index]++;
		if (max < digits[index]) max = digits[index];
	}
	return max;
}


int main()
{
	string number;
	int digits[10];

	//default 0
	for (int i = 0; i < 10; i++)
	{
		digits[i] = 0;
	}

	//input varification
	if (InputHandle(&number) == -1)
	{
		cout << "-1" << endl;
		system("pause");
		return 0;
	}


	int maxNumber = DigitHandle(number,digits);

	for (int i = 0; i < 10; i++)
	{
		if (digits[i] == maxNumber) cout <<i<< "-->" << maxNumber << endl;
	}

	system("pause");
	return 0;

}