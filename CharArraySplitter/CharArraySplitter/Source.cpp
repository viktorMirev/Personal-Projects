/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Viktor Mirev
* @idnumber 62231
* @task 2
* @compiler VC
*
*/

#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;

int const NUMBER_OF_SPLITTERS = 7;
char const HORIZONTAL_LINE_CHAR = '-';
char const VERTICAL_LINE_CHAR = '|';

struct MyString
{
	char * content;
	int length;
};

char Splitters[7] = { ' ', '!',',','.','?',';',':' };

void InputHandler(MyString * input)
{
	char currSymbol;
	cin >> currSymbol;
	while (currSymbol!='\n' && currSymbol != '\r')
	{
		(input->content)[input->length] = currSymbol;
		input->length++;
		currSymbol = getchar();
	}
}

bool IsSplitter(char a)
{
	for (size_t i = 0; i < NUMBER_OF_SPLITTERS; i++)
	{
		if (a == Splitters[i]) return true;
	}
	return false;
}

int Split(MyString * input)
{
	int longestPart = 0;
	int currLenght = 0;
	for (size_t i = 0; i < input->length; i++)
	{
		if (IsSplitter(input->content[i]))
		{
			if (currLenght > longestPart)
			{
				longestPart = currLenght;
			}
			currLenght = 0;
			input->content[i] = 0;
		}
		else
		{
			currLenght++;
		}
	}
	

	return max(longestPart,currLenght);
}

void PrintHorizontalLine(char a, int number)
{
	for (size_t i = 0; i < number; i++)
	{
		cout << a;
	}
	cout << endl;
}

void Print(MyString * input, int spacing)
{
	//top
	PrintHorizontalLine(HORIZONTAL_LINE_CHAR, spacing + 2);

	//the current reading position
	int position = 0;

	while (position<input->length)
	{
		//we skip the splitters who are marked with 0 (null)
		while (input->content[position] == 0)
		{
			position++;
		}
		//if we reach the end break
		if (position >= input->length) break;

		//cell border
		cout << VERTICAL_LINE_CHAR;
		
		//a new word is printed
		int len = 0;
		while (input->content[position]!=0 && position<input->length)
		{
			cout << input->content[position];
			position++;
			len++;
		}
		cout.width(spacing - len +1 );

		//cell border 
		cout << VERTICAL_LINE_CHAR<<endl;

	}
	//bottom
	PrintHorizontalLine('-', spacing + 2);	
}


int main()
{
	MyString input = { new char[100], 0 };
	
	InputHandler(&input);
	int spacing = Split(&input);

	Print(&input, spacing);
	//system("pause");
	return 0;
}