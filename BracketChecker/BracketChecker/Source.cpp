#include<iostream>
using namespace std;

int bracketCounter = 0;

bool EqualityBrecketChecker(char * indx)
{
	//terminating zero
	if (*indx == '\0') return true;

	if (*indx == '(') 	bracketCounter++;

	if (*indx == ')') 
	{
		bracketCounter--;
		//if the counter is less than 0
		//there was ')' and no '(' to open it
		if (bracketCounter < 0) return false; 
	}
	
	indx++;

	//return the function for the next
	return EqualityBrecketChecker(indx);
}

int main()
{
	char * arr = new char[100];
	cin.getline(arr, 100);
	
	//if the bracketCounter is !=0 we have different number '(' and ')'
	if (EqualityBrecketChecker(arr) && bracketCounter == 0)
		cout << "correct" << endl;
	else
	{
		cout << "incorrect" << endl;
	}

	return 0;
}