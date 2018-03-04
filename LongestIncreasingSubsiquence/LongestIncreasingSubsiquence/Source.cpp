/*
	The aim is to find the longest increasing subsiquence
	there is no need the elements to border each other
	example 9 6 2 7 4 7 6 5 8 4
	result 2 4 7 8
*/

#include<iostream>
using namespace std;

struct Siquence
{
	int * lis;
	int length;
};


Siquence * LIS(int * input, int length)
{
	int maxLens[100];   //Here we save for every index the current max length
	int prevEls[100];	//here we save the index of the prev element of the siq

	/*for (size_t i = 0; i < length; i++) //each element points himself
	{
		prevEls[i] = i;
	}*/

	for (size_t i = 0; i < length; i++)  // to be sure that all here are 1s 
	{
		maxLens[i] = 1;
	}



	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if ((input[j] < input[i]) && maxLens[i]<=maxLens[j]) // we found an element which is less than the current so , party !
			{
				maxLens[i] = maxLens[j] + 1;  //now the max length is the length in j but + 1 
				prevEls[i] = j; //we point to the prev elementso we can find them at the end
			}
		}
	}

	int max = 0;
	int index;

	for (size_t i = 0; i < length; i++)
	{
		if (maxLens[i] > max)
		{
			max = maxLens[i];
			index = i;
		}
	}

	int * lis = new int[max];
	int currIndex = index;
	for (size_t i = 0; i < max; i++)
	{
		lis[max - i - 1] = input[currIndex];
		currIndex = prevEls[currIndex];
	}

	Siquence * result = new Siquence;
	result->length = max;
	result->lis = lis;

	return result;
}


int main()
{
	int n;
	cin >> n;
	int * input = new int[n];
	for (size_t i = 0; i < n; i++)
	{
		cin>>input[i];
	}

	Siquence * result = LIS(input, n);
	for (size_t i = 0; i < result->length; i++)
	{
		cout << result->lis[i] << " ";
	}
	return main();
}
