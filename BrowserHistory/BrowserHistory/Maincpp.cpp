#include<iostream>
#include"BrowserHistory.h"
using namespace std;

int main()
{
	BrowserHistory * b1 = new BrowserHistory(3);
	for (size_t i = 0; i < 3; i++)
	{
		b1->AddNewHistoryEntry();
	}
	b1->PrintAll();
	b1->AddNewHistoryEntry();
	return main();
}