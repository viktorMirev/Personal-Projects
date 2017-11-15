/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Viktor Mirev
* @idnumber 62231
* @task 5
* @compiler VC
*
*/



#include<iostream>
using namespace std;

int main()
{
	int number;
	int lastDigit = 0;
	int firstDigit = 0;
	int numLenght = 1;
	int helpNum;

	cin >> number;

	helpNum = number; // we will devide this number;

	lastDigit = number % 10;
	number /= 10; //we have the last digit so we can remove it and now te number is with maximum 9 digits


	if (number == 0) cout << lastDigit << endl; //the last would be the first (the number of digits is 1)
	else
	{
		numLenght++; //now we know for sure that the lenght is at least 2 digits;
		helpNum /= 100;
		if (helpNum != 0)
		{
			numLenght++; //now we know for sure that the lenght is at least 3 digits;
			helpNum /= 10;
			if (helpNum != 0)
			{
				numLenght++;//now we know for sure that the lenght is at least 4 digits;
				helpNum /= 10;
				if (helpNum != 0)
				{
					numLenght++;//now we know for sure that the lenght is at least 5 digits;
					helpNum /= 10;
					if (helpNum != 0)
					{
						numLenght++;//now we know for sure that the lenght is at least 6 digits;
						helpNum /= 10;
						if (helpNum != 0)
						{
							numLenght++;//now we know for sure that the lenght is at least 7 digits;
							helpNum /= 10;
							if (helpNum != 0)
							{
								numLenght++;//now we know for sure that the lenght is at least 8 digits;
								helpNum /= 10;
								if (helpNum != 0)
								{
									numLenght++;//now we know for sure that the lenght is at least 9 digits;
									helpNum /= 10;
									if (helpNum != 0)
									{
										numLenght++;//now we know for sure that the lenght is 10 digits;
										firstDigit = helpNum;
									}
									else firstDigit = number / (int)(pow(10, numLenght - 2));
								}
								else firstDigit = number / (int)(pow(10, numLenght - 2));
							}
							else firstDigit = number / (int)(pow(10, numLenght - 2));
						}
						else firstDigit = number / (int)(pow(10, numLenght - 2));
					}
					else firstDigit = number / (int)(pow(10, numLenght - 2));
				}
				else firstDigit = number / (int)(pow(10, numLenght - 2));
			}
			else firstDigit = number / (int)(pow(10, numLenght - 2));
		}
		else firstDigit = number / (int)(pow(10, numLenght - 2));

		// this section is made this way because you can type a number which is in the boundaries of int but 
		// with reversed 1st and last it may overflow

		int middleSection = number % ((int)pow(10, numLenght - 2));

		if (middleSection == 0)
		{
			cout << lastDigit << firstDigit << endl;
		}
		else
		{
			cout << lastDigit << middleSection << firstDigit << endl;
		}
	}

	return main();

}