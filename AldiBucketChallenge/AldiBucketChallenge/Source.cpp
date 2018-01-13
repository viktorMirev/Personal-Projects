#include<iostream>
using namespace std;

struct Bucket
{
	int capacity;
	int currLoad=0;
	Bucket(int c)
	{
		capacity = c;
	}
};

bool Success(Bucket * b1,Bucket * b2, int capacityIWant, int b1Curr, int b2Curr)
{
	return (b2Curr == capacityIWant || b1Curr == capacityIWant);
}

int PathFinder(int command, int currStep, Bucket * b1, Bucket * b2,int capacityIWant, int b1Curr,int b2Curr)
{
	//bottom of the recursion
	if (Success(b1, b2, capacityIWant,b1Curr,b2Curr)) return 0;

	switch (command)
	{
		//fill first
		case 1:
		{
			b1Curr = b1->capacity;
			break;
		}//fill second
		case 2:
		{
			b2Curr = b2->capacity;
			break;
		}
		//first in second
		case 3:
		{
			int diff = b2->capacity - b2Curr;
			if (b1Curr <= diff)
			{
				b2Curr += b1Curr;
			}
			else
			{
				b2Curr = b2->capacity;
			}
			b1Curr -= diff;
			break;
		}
		//second in first
		case 4:
		{
			int diff = b1->capacity - b1Curr;
			if (b2Curr <= diff)
			{
				b1Curr += b2Curr;
			}
			else
			{
				b1Curr = b1->capacity;
			}
			b2Curr -= diff;
			break;
		}
		default: break;

	}

	int one=-1;
	int two=-1;
	int three=-1;
	int four=-1;

	if (b1Curr == b1->capacity && b2Curr == b2->capacity) return 10000;


	//ako nqkoe varne 0 napravo da vrashta i to 0
	if (b1->capacity != b1Curr) one = PathFinder(1, currStep + 1, b1, b2, capacityIWant,b1Curr,b2Curr);
	if (b2->capacity != b2Curr) two = PathFinder(2, currStep + 1, b1, b2, capacityIWant, b1Curr, b2Curr);
	if (b2->capacity != b2Curr) three = PathFinder(3, currStep + 1, b1, b2, capacityIWant, b1Curr, b2Curr);
	if (b1->capacity != b1Curr) four = PathFinder(4, currStep + 1, b1, b2, capacityIWant, b1Curr, b2Curr);

	

	int min = 100000;
	if (one >= 0 && one < min) min = one;
	if (two >= 0 && two < min) min = two;
	if (three >= 0 && three < min) min = three;
	if (four >= 0 && four < min) four = one;

	return min;
}

int main()
{
	int b1cap, b2cap;
	int capacityIWant;
	

	cin >> b1cap >> b2cap >> capacityIWant;

	Bucket * b1 = new Bucket(b1cap);
	Bucket * b2 = new Bucket(b2cap);

	cout << PathFinder(0,1, b1, b2, capacityIWant,0,0) << endl;

	return main();
}