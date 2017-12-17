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
#include<string>

using namespace std;

struct Palindrome
{
	string content;
	int count = 0;
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
int CountPalindromes(Palindrome palindromes[100],string & text, int maxNum)
{
	int count = 0;
	int startPosition = 0;
	for (startPosition = 0; startPosition  < maxNum; startPosition ++)
	{
		for (int i = 2; i <= maxNum-startPosition; i++)
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
void PrintResult(Palindrome palindromes[100], int count)
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

int main()
{
	string text;
	cout << "Please enter the text for check if it contains palindromes" << endl;
	getline(cin,text);
	Palindrome palindromes[100];
	//we pass the lenght to the function because the number of the palindromes cannot be more than it
	int numberOfPalindormes = CountPalindromes(palindromes,text, text.length());

	PrintResult(palindromes, numberOfPalindormes);
	//system("pause");
	return 0;
	
}