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
using namespace std;

int const NUMBER_OF_SPLITTERS = 7;

struct MyString
{
	char content[100];
	int length;
};

char Splitters[7] = { ' ', '!',',','.','?',';',':' };

MyString * InputHandler()
{
	char data[100];
	int itt = 0;
	char currSymbol;
	cin >> currSymbol;
	while (currSymbol!='\n')
	{
		data[itt] = currSymbol;
		itt++;
		cin >> currSymbol;
	}
	MyString input = { *data,itt };
	return &input;
}

bool IsSplitter(char a)
{
	for (size_t i = 0; i < NUMBER_OF_SPLITTERS; i++)
	{
		if (a == Splitters[i]) return true;
	}
	return false;
}

void Split(MyString * input)
{
	//MyString splittedData[100];
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
}

void Print(MyString * input)
{

}


int main()
{
	MyString * input = InputHandler();
	Split(input);
	Print(input);
}