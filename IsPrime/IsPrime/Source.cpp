/*
	Viktor Mirev
	Prime number checker
*/

#include<iostream>

using namespace std;

bool IsPrime(int n)
{
	bool prime = false;
	for (int i = 2; i < sqrt(n); i++)
	{
		if (n%i == 0)
		{
			prime = true;
			cout << i << endl;
		}
	}
	return prime;
}

int main()
{
	int n;
	cout << "enter the num you want to check" << endl;

	cin >> n;


	cout<<IsPrime(n)<<endl;

	return main();
}