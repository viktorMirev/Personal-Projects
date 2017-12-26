/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Viktor Stoyanov Mirev
* @idnumber 62231
* @task 4
* @compiler VC
*
*/


#include<iostream>

using namespace std;

struct MyString
{
	char * content;
	int length = 0;
};

//checks if a substring is a palindrome
bool IsPalindrome(string & text)
{
	int textLength = text.length();
	for (size_t i = 0; i < textLength/2; i++)
	{
		if (text[i] != text[textLength - 1 - i]) return false;
	}
	return true;
}


//gets all substrings and test them for palindromness
int CountPalindromes(MyString * text)
{
	int count = 0;
	int startPosition = 0;
	int length = text->length;
	for (startPosition = 0; startPosition  <length ; startPosition ++)
	{
		for (int i = 2; i <= length-startPosition; i++)
		{
			string currSub = text.substr(startPosition, i);
			if (IsPalindrome(currSub))
			{
				bool isAlreadyFound = false;
				//check
				for (int j = 0; j < count; j++)
				{
					if (palindromes[j].content == currSub)
					{
						palindromes[j].count++;
						isAlreadyFound = true;
						break;
					}
				}

				if (!isAlreadyFound)
				{
					palindromes[count].content = currSub;
					palindromes[count].count = 1;
					count++;
				}
				
			}
		}
		
	}
	return count;
}
void PrintResult(MyPalindrome palindromes[100], int count)
{
	if (count == 0)
	{
		cout << "NO!" << endl;
	}
	else
	{
		//printing
		for (size_t i = 0; i < count; i++)
		{
			cout << palindromes[i].content << " - " << palindromes[i].count << endl;
		}
	}
}

void InputHandle(MyString * text)
{
	char currSymbol;
	currSymbol = getchar();
	while (currSymbol != '\n' && currSymbol != '\r')
	{
		text->content[text->length] = currSymbol;
		text->length++;
		currSymbol = getchar();
	}
}

int main()
{
	MyString text = { new char[100],0};

	cout << "Please enter the text for check if it contains palindromes" << endl;
	InputHandle(&text);

	int numberOfPalindormes = CountPalindromes(&text);

	PrintResult(palindromes, numberOfPalindormes);
	system("pause");
	return 0;
	
}