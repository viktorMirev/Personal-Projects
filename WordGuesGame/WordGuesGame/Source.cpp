#include<iostream>
using namespace std;

struct MyString
{
	char * content;
	int length;
};

MyString DataBase[100] =
{
	{ new char[4]{ 't','e','s', 't' },4 },
	{ new char[7]{ 's','t','u','d','e','n', 't' },7},
	{ new char[12]{ 'r','e','f','r','i','g', 'e','r','a','t','o','r' },12 },
};

int main()
{
	cout << "Enter the number of guesses allowed" << endl;
	int numberOfGueses = 5;
	cin >> numberOfGueses;

	int currNumberWord = rand()%3;
	MyString currWord = DataBase[currNumberWord];
	MyString knownSymbols = { new char[100]{currWord.content[0], currWord.content[currWord.length-1]},2};
	

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
		if(isNew)
		{
			for (size_t i = 1; i < currWord.length; i++)
			{
				if (gues == currWord.content[i])
				{
					knownSymbols.content[knownSymbols.length] = gues;
					knownSymbols.length++;
					success = true;
				}
			}
		}

		if (success)
		{
			if (knownSymbols.length == currWord.length)
			{
				cout << "Congratulations, you win!" << endl;
				cout << "The word is '";
				for (size_t i = 0; i < currWord.length; i++)
				{
					cout << currWord.content[i];
				}
				cout <<"' ."<< endl;
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
	
	return main();
}