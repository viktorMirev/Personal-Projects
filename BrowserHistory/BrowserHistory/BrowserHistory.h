#pragma once

#include"HistoryEntry.h"

class  BrowserHistory
{
public:

	//constructor 
	 BrowserHistory(int n);

	 //destructor
	~ BrowserHistory();

	//copy constructor
	BrowserHistory(const BrowserHistory& other);

	//opeator=
	void operator=(const BrowserHistory& other);

	//concatinating function
	//we use pointer
	BrowserHistory* Concat(const BrowserHistory& other);

	//returns the number of entries for the given month
	int NumberOfEntriesPerMonth(int month);

	//return the month with the most entries
	int MonthWithMostEntries();

	//selectors

	//get maxLen
	//int GetMaxLen();

	//print all entries
	void PrintAll();

	//mutators

	//insert from keyboard new entry
	void AddNewHistoryEntry();
	
	//add existing entry
	void AddExistingEntry(const HistoryEntry& entry);

	//remove the last entry
	void RemoveLastEntry();

private:
	int maxLenght;
	int currLenght;
	HistoryEntry * history;
	void DeleteHistory();
	void CopyHistoryFromOther(const BrowserHistory& other);
	bool IsFull();
};
