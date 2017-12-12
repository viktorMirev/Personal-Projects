#include<iostream>

using namespace std;

//biggest possible theoretically
int const BIGGEST_POSSIBLE = 1860000;


//we calculate them before the check in order to save time
void FactorielIt(int* basicFactoriels, int size)
{
	for (size_t i = 2; i < 10; i++)
	{
		basicFactoriels[i] = basicFactoriels[i - 1] * i;
	}
}

//ckecks if number equals the sum of the factoriels of its digits
bool Checker(int* basicFactoriels, int size, int Num)
{
	int currSum = 0;
	int currNum = Num;
	while(currNum!=0)
	{
		currSum += basicFactoriels[currNum % 10];
		currNum /= 10;
		if (currSum > Num)	return false;
	}

	if (currSum == Num) return true;

	return false;
}

int main()
{
	int basicFactoriels[10] = { 1,1 };
	FactorielIt(basicFactoriels,10);
	int counter = 0;
	while (true)
	{
		if (Checker(basicFactoriels, 10, (BIGGEST_POSSIBLE - counter)) == true)
		{
			cout << "biggest: "<<BIGGEST_POSSIBLE - counter << endl;
			break;
		}
		cout << BIGGEST_POSSIBLE - counter << endl;
		//counter++;
	}
	
	system("pause");
	return 0;
}
