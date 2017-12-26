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
	int numberOfOccurrences = 0;
};

//checks if a substring is a palindrome
bool IsPalindrome(int left, int right,MyString * text)
{
	/*int textLength = text.length();
	for (size_t i = 0; i < textLength/2; i++)
	{
		if (text[i] != text[textLength - 1 - i]) return false;
	}
	return true;*/
}

void SubstringValueCopy(int left, int right, MyString * text, MyString * palindrome)
{
	int writePosition = 0;
	for (size_t i = left; i < right; i++)
	{
		palindrome->content[writePosition] = text->content[i];
		writePosition++;
	}
	palindrome->length = (right - left);
	palindrome->numberOfOccurrences = 1;
}

bool SubstringEquality(int left, int right, MyString * text, MyString *  palindrome)
{
	if (palindrome->length != right - left) return false;

	int palindromePosition = 0;
	for (size_t i = left; i < right; i++)
	{
		if (palindrome->content[palindromePosition] != text->content[i]) return false;
		palindromePosition++;
	}
	return true;
}

//gets all substrings and test them for palindromness
int CountPalindromes(MyString * text, MyString palindromes[100])
{
	int count = 0;
	int startPosition = 0;
	int length = text->length;
	for (startPosition = 0; startPosition  <length ; startPosition ++)
	{
		for (int i = 2; i <= length-startPosition; i++)
		{
			//left & right borders are the boundaries of the substring
			int currRight = i+startPosition;
			int currLeft = startPosition;
			if (IsPalindrome(currLeft,currRight, text))
			{
				bool isAlreadyFound = false;
				//check
				for (int j = 0; j < count; j++)
				{
					if (SubstringEquality(currLeft,currRight, text, &palindromes[j]))
					{
						palindromes[j].numberOfOccurrences++;
						isAlreadyFound = true;
						break;
					}
				}

				if (!isAlreadyFound)
				{
					SubstringValueCopy(currLeft, currRight, text, &palindromes[count]);
					count++;
				}
				
			}
		}
		
	}
	return count;
}
void PrintResult(MyString palindromes[100], int count)
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
	//input text
	MyString text = { new char[100],0};
	//here we save the palindromes we found
	MyString palindromes[100];
	cout << "Please enter the text for check if it contains palindromes" << endl;

	InputHandle(&text);

	int numberOfPalindormes = CountPalindromes(&text,palindromes);

	PrintResult(palindromes, numberOfPalindormes);
	system("pause");
	return 0;
	
}