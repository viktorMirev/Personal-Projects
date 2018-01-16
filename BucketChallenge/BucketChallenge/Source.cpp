#include<iostream>
#include<algorithm>
using namespace std;

//global variables 
//we use them because in the recursion they will be parasite

int bucketOneCapacity;
int bucketTwoCapacity;
int wantedCapacity;
bool usedStatesArray[21][21];

const int MAX_INT = INT16_MAX;

int Route(int currFirst, int currSecond, int numOfStpes)
{
	//cout << "current attitude " << currFirst << " " << currSecond << endl;
	if (currFirst == wantedCapacity || currSecond == wantedCapacity)
	{
		return numOfStpes;
	}

	int firstPoss = MAX_INT;
	int secondPoss = MAX_INT;
	int thirdPoss = MAX_INT;
	int fourthPoss = MAX_INT;
	int fifthPoss = MAX_INT;
	int sixthPoss = MAX_INT;

	if (!usedStatesArray[bucketOneCapacity][currSecond])
	{
		/*cout << "current attitude " << currFirst << " " << currSecond << endl;
		cout << "fillin first" << endl;
		cout << bucketOneCapacity << " " << currSecond << endl;*/
		usedStatesArray[bucketOneCapacity][currSecond] = true;
		firstPoss = Route(bucketOneCapacity, currSecond, numOfStpes + 1);
	}

	if (!usedStatesArray[currFirst][bucketTwoCapacity])
	{
		/*cout << "current attitude " << currFirst << " " << currSecond << endl;
		cout << "fillin second" << endl;
		cout << currFirst << " " << bucketTwoCapacity << endl;*/
		usedStatesArray[currFirst][bucketTwoCapacity] = true;
		secondPoss = Route(currFirst, bucketTwoCapacity, numOfStpes + 1);
	}

	if (!usedStatesArray[0][currSecond])
	{
		/*cout << "current attitude " << currFirst << " " << currSecond << endl;
		cout << "dropp first" << endl;
		cout << 0 << " " << currSecond << endl;*/
		usedStatesArray[0][currSecond] = true;
		thirdPoss = Route(0, currSecond, numOfStpes + 1);
	}

	if (!usedStatesArray[currFirst][0])
	{
		/*cout << "current attitude " << currFirst << " " << currSecond << endl;
		cout << "dropp second" << endl;
		cout << currFirst << " " << 0 << endl;*/
		usedStatesArray[currFirst][0] = true;
		fourthPoss = Route(currFirst, 0, numOfStpes + 1);
	}

	//first to second
	int diff1 = bucketTwoCapacity - currSecond;
	if (diff1 <= currFirst)
	{
		diff1 = currFirst - diff1;
	}
	else
	{
		diff1 = 0;
	}

	if (!usedStatesArray[diff1][min((currSecond + currFirst), bucketTwoCapacity)])
	{
		/*cout << "current attitude " << currFirst << " " << currSecond << endl;
		cout << "first to second" << endl;
		cout << diff1 << " " << min((currSecond + currFirst), bucketTwoCapacity) << endl;*/

		usedStatesArray[diff1][min((currSecond + currFirst), bucketTwoCapacity)] = true;
		fifthPoss = Route(diff1, min((currSecond + currFirst), bucketTwoCapacity), numOfStpes + 1);
	}



	//second to first
	int diff2 = bucketOneCapacity - currFirst;
	if (diff2 <= currSecond)
	{
		diff2 = currSecond - diff2;
	}
	else
	{
		diff2 = 0;
	}

	if (!usedStatesArray[min((currFirst + currSecond), bucketOneCapacity)][diff2])
	{
		/*cout << "current attitude " << currFirst << " " << currSecond << endl;
		cout << "second to first" << endl;
		cout << min((currFirst + currSecond), bucketOneCapacity) << " " << diff2 << endl;*/

		usedStatesArray[min((currFirst + currSecond), bucketOneCapacity)][diff2] = true;
		sixthPoss = Route(min((currFirst + currSecond), bucketOneCapacity), diff2, numOfStpes + 1);
	}


	usedStatesArray[currFirst][currSecond] = false;

	return  min(min(min(min(firstPoss, secondPoss), min(thirdPoss, fourthPoss)), fifthPoss), sixthPoss);
}

int main()
{
	cout << "Insert one one line the capacity of the first, the second bucket & the wanted quantity" << endl;
	cin >> bucketOneCapacity >> bucketTwoCapacity >> wantedCapacity;
	int result = Route(0, 0, 0);
	swap(bucketOneCapacity, bucketTwoCapacity);
	result = min(Route(0, 0, 0), result);
	if (result == MAX_INT) cout << -1 << endl;
	else
	{
		cout << result<<endl;
	}
	return 0;
}