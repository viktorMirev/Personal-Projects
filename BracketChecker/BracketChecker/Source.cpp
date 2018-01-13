/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2017/2018
*
* @author Viktor Mirev
* @idnumber 62231
* @task 1
* @compiler VC
*
*/


#include<iostream>
using namespace std;

//no way to use something different than this
//because the other possibility is going to 
//send this counter in the stack multiple times 
//which is bad and can cause stack overflow
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
	if (EqualityBrecketChecker(arr) && bracketCounter == 0) 	cout << "correct" << endl;

	else cout << "incorrect" << endl;

	//dealing with the possible memory leak
	delete[] arr;

	return 0;
}