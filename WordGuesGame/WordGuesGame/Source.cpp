/**
*
* Solution to second homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author VIktor Mirev
* @idnumber 62231
* @task 1
* @compiler VC
*
*/


#include<iostream>
using namespace std;

struct MyString
{
	char * content;
	int length;
};

MyString DataBase[10] =
{
	{ new char[4]{ 't','e','s', 't' },4 },
	{ new char[7]{ 's','t','u','d','e','n','t' },7},
	{ new char[12]{ 'r','e','f','r','i','g','e','r','a','t','o','r' },12 },
	{ new char[7]{ 'r','e','f','u','g','e','e'},7 },
	{ new char[9]{ 'a','b','a','n','d','o','n','e','d' },9 },
	{ new char[7]{ 'r','e','f','r','e','s','h'},7 },
	{ new char[9]{ 'v','a','n','d','a','l', 'i','s','m'},9 },
	{ new char[11]{ 'd','e','s','t','r','u','c','t','i','o','n' },11 },
	{ new char[8]{ 'h','u','m','a','n','i','t','y'},8 },
	{ new char[12]{ 's','a','t','i','s','f','a','c','t', 'i', 'o','n' },12 }
};

int InputHandler()
{
	int numberOfGueses;
	cout << "Enter the number of guesses allowed" << endl;
	cin >> numberOfGueses;
	return numberOfGueses;
}

void GameStart(int numberOfGueses)
{
	//to be real rand
	int currNumberWord = rand();
	currNumberWord = rand();
	currNumberWord %= 10;

	//the time when we use the database (only in this func)
	MyString currWord = DataBase[currNumberWord];

	//here are saved the guessed words
	MyString knownSymbols = { new char[100]{ currWord.content[0]},1 };

	//there is the possibility of equal first and last symbol
	if (currWord.content[currWord.length - 1] != currWord.content[0])
	{
		knownSymbols.content[1] = currWord.content[currWord.length - 1];
		knownSymbols.length = 2;
	}

	//we need to know the number of uniqe symbols
	char uniqeSymbols[100];
	int numberOfUniqe = 0;
	for (size_t i = 0; i < currWord.length; i++)
	{
		bool isUniqe = true;
		for (size_t j = 0; j < numberOfUniqe; j++)
		{
			if (currWord.content[i] == uniqeSymbols[j])
			{
				isUniqe = false;
				break;
			}
		}
		if (isUniqe)
		{
			uniqeSymbols[numberOfUniqe] = currWord.content[i];
			numberOfUniqe++;
		}
	}

	//here the number of uniqe is lowered because the first and the second are already found
	numberOfUniqe -= knownSymbols.length;

	while (numberOfGueses != 0)
	{
		for (size_t i = 0; i < currWord.length; i++)
		{
			bool found = false;
			for (size_t j = 0; j < knownSymbols.length; j++)
			{
				if (currWord.content[i] == knownSymbols.content[j])
				{
					cout << currWord.content[i];
					found = true;
					break;
				}
			}
			if (!found) cout << "_";
		}
		cout << endl;
		cout << "Attempts left: " << numberOfGueses << endl;
		char gues;
		cin >> gues;
		bool isNew = true;

		//check if it is already guessed;
		for (size_t i = 0; i < knownSymbols.length; i++)
		{
			if (gues == knownSymbols.content[i])
			{
				isNew = false;
				break;
			}
		}
		bool success = false;
		if (isNew)
		{
			for (size_t i = 1; i < currWord.length; i++)
			{
				if (gues == currWord.content[i])
				{
					knownSymbols.content[knownSymbols.length] = gues;
					knownSymbols.length++;
					success = true;
					break;
				}
			}
		}

		if (success)
		{
			numberOfUniqe--;
			if (numberOfUniqe == 0)
			{
				cout << "Congratulations, you win!" << endl;
				cout << "The word is '";
				for (size_t i = 0; i < currWord.length; i++)
				{
					cout << currWord.content[i];
				}
				cout << "' ." << endl;
				break;
			}
			else
			{
				cout << "Success!" << endl;
			}

		}
		else
		{
			numberOfGueses--;
			cout << "Error!" << endl;
		}


	}
	if (numberOfGueses == 0) cout << "You Lost!" << endl;

}

int main()
{
	int numberOfGueses = InputHandler();

	GameStart(numberOfGueses);

	return 0;
}