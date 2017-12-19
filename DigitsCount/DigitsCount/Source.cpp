#include<iostream>
#include<string>

using namespace std;

void InputHandle(string * number)
{
	cin >> * number;
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
	for (int i = 0; i < 10; i++)
	{
		digits[i] = 0;
	}
	InputHandle(&number);

	int maxNumber = DigitHandle(number,digits);
	cout << maxNumber << endl;
	for (int i = 0; i < 10; i++)
	{
		//cout <<i<<"-->"<< digits[i] << endl;
		if (digits[i] == maxNumber) cout <<i<< "-->" << maxNumber << endl;
	}
	system("pause");
	return main();

}