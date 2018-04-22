#include<iostream>
#include"BrowserHistory.h"
#include "Main.h"
using namespace std;


//creates test browsing data
BrowserHistory * CreateTestBrowser()
{
	const char * url1 = "test-1";
	HistoryEntry * h_entry1 = new HistoryEntry();
	h_entry1->date = 10;
	h_entry1->Url = new char[7];
	memcpy(h_entry1->Url, url1, 7);

	const char * url2 = "test-2";
	HistoryEntry * h_entry2 = new HistoryEntry();
	h_entry2->date = 9;
	h_entry2->Url = new char[7];
	memcpy(h_entry2->Url, url2, 7);

	const char * url3 = "test-3";
	HistoryEntry * h_entry3 = new HistoryEntry();
	h_entry3->date = 10;
	h_entry3->Url = new char[7];
	memcpy(h_entry3->Url, url3, 7);

	const char * url4 = "test-4";
	HistoryEntry * h_entry4 = new HistoryEntry();
	h_entry4->date = 1;
	h_entry4->Url = new char[7];
	memcpy(h_entry4->Url, url4, 7);

	BrowserHistory * b = new BrowserHistory(10);
	b->AddExistingEntry(*h_entry1);
	b->AddExistingEntry(*h_entry2);
	b->AddExistingEntry(*h_entry3);
	b->AddExistingEntry(*h_entry4);

	return b;
}

//Test the ability to add entry from keyboard
void AddTest(BrowserHistory * b1, int number)
{
	cout << "TEST ADD FROM KEYBOARD ENTRY" << endl;
	cout << endl;
	cout << "Enter " << number << " entries for b1" << endl;
	cout << endl;
	for (size_t i = 0; i < number; i++)
	{
		b1->AddNewHistoryEntry();
	}
	b1->PrintAll();
}

//test the ability to detect overflow of the memory of the browser
// give it a browser with for example 5 entries and max of 5 entries
// if you try to add one more it should display error;
void TestOverflow()
{
	cout << "TEST FOR OVERFLOW OF MEMORY" << endl;
	cout << endl;
	//we test with  memory = 1
	BrowserHistory * b = new BrowserHistory(1);
	b->AddNewHistoryEntry();

	cout << endl;
	cout << "add the entry which should overflow from keyboard test" << endl;
	cout << endl;

	b->AddNewHistoryEntry();

	cout << endl;
	cout << "add the entry which should overflow from existing entry test" << endl;
	cout << endl;

	b->AddExistingEntry(*(new HistoryEntry()));
}

void MonthWithMostEntriesTest()
{
	cout << "TEST FOR THE MONTH WITH MOST ENTRIES" << endl;
	cout << endl;

	BrowserHistory * b = CreateTestBrowser();

	cout << "Month with most entries: " << b->MonthWithMostEntries() << endl;
	cout << "Should be 10" << endl;
}

void AddExistingEntryTest()
{
	cout << "TEST ADD EXISTING ENTRY" << endl;
	cout << endl;

	const char * url = "test1";
	HistoryEntry * h_entry = new HistoryEntry();
	h_entry->date = 10;
	h_entry->Url = new char[6];
	memcpy(h_entry->Url, url, 6);

	BrowserHistory * b = new BrowserHistory(10);
	b->AddExistingEntry(*h_entry);

	cout << "Result: " << endl;
	cout << endl;

	b->PrintAll();

}

void DeleteLastEntryTest(BrowserHistory * b1)
{
	cout << "TEST DELETE LAST EXISTING ENTRY" << endl;
	cout << endl;
	b1->PrintAll();

	cout << endl;
	cout << "Removing last" << endl;
	cout << endl;

	b1->RemoveLastEntry();
	b1->PrintAll();

}

void CopyConstructorTest(BrowserHistory * bH)
{
	cout << "TEST FOR THE COPY CONSTRUCTOR" << endl;
	cout << endl;
	cout << "Print the original" << endl;
	bH->PrintAll();

	BrowserHistory * new_Br = new BrowserHistory(*bH);

	cout << "Print the new" << endl;

	new_Br->PrintAll();
}

void EntriesPerMonthTest()
{
	cout << "TEST FOR THE ENTRIES PER MONTH" << endl;
	cout << endl;

	BrowserHistory * b = CreateTestBrowser();

	cout << "Month 10 has " << b->NumberOfEntriesPerMonth(10) << " entries: " << endl;
	cout << "sould be 2" << endl;

}

void ConcatTest(BrowserHistory * bH)
{
	cout << "TEST FOR THE CONCAT FUNCTION" << endl;
	cout << endl;
	BrowserHistory * first = CreateTestBrowser();

	cout << "PRINT the first" << endl;
	cout << endl;
	first->PrintAll();
	cout << endl;

	cout << "PRINT the second" << endl;
	cout << endl;

	bH->PrintAll();

	BrowserHistory * concat = first->Concat(*bH);

	cout << "PRINT the CONCATIONATED" << endl;
	cout << endl;

	concat->PrintAll();

}

int main()
{
	BrowserHistory * bH = new BrowserHistory(3);

	AddTest(bH, 3);
	cout << endl;
	cout << endl; 
	cout << endl;

	CopyConstructorTest(bH);
	cout << endl;
	cout << endl;
	cout << endl;

	DeleteLastEntryTest(bH);
	cout << endl;
	cout << endl;
	cout << endl;

	TestOverflow();
	cout << endl;
	cout << endl;
	cout << endl;

	AddExistingEntryTest();
	cout << endl;
	cout << endl;
	cout << endl;

	MonthWithMostEntriesTest();
	cout << endl;
	cout << endl;
	cout << endl;

	EntriesPerMonthTest();
	cout << endl;
	cout << endl;
	cout << endl;

	ConcatTest(bH);
	cout << endl;
	cout << endl;
	cout << endl;

	return 0;
}