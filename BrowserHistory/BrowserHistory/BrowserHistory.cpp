#include<iostream>

#include"BrowserHistory.h"

void BrowserHistory::DeleteHistory()
{
	for (size_t i = 0; i < this->currLenght; i++)
	{
		delete[] history[i].Url;
	}
	delete[] this->history;
}

void BrowserHistory::CopyHistoryFromOther(const BrowserHistory & other)
{
	this->history = new HistoryEntry[other.maxLenght];
	for (size_t i = 0; i < other.currLenght; i++)
	{
		this->history[i].date = other.history[i].date;

		//the lenght of the url we want to copy + 1 (the terminating zero)
		int len = strlen(other.history[i].Url) +1 ;

		this->history[i].Url = new char[len];

		memcpy(history[i].Url, other.history[i].Url, len);
	}
	this->currLenght = other.currLenght;
}

bool BrowserHistory::IsFull()
{
	return this->currLenght == this->maxLenght;
}

BrowserHistory::BrowserHistory(int n)
{
	this->history = new HistoryEntry[n];
	this->currLenght = 0;
	this->maxLenght = n;
}

BrowserHistory::~BrowserHistory()
{
	this->DeleteHistory();
}

BrowserHistory::BrowserHistory(const BrowserHistory & other)
{
	this->CopyHistoryFromOther(other);
	this->maxLenght = other.maxLenght;
}

void BrowserHistory::operator=(const BrowserHistory & other)
{
	this->DeleteHistory();
	this->maxLenght = other.maxLenght;
	this->CopyHistoryFromOther(other);
}

BrowserHistory * BrowserHistory::Concat(const BrowserHistory & other)
{
	//we create the concatinated browserhistory to be with maximum
	//length the sum of the max lengths of the other 2
	BrowserHistory * concat = new BrowserHistory(this->maxLenght + other.maxLenght);

	for (size_t i = 0; i < this->currLenght; i++)
	{
		concat->AddExistingEntry(this->history[i]);
	}
	for (size_t i = 0; i < other.currLenght; i++)
	{
		concat->AddExistingEntry(other.history[i]);
	}
	return concat;
}

int BrowserHistory::NumberOfEntriesPerMonth(int month)
{
	int count = 0;
	for (size_t i = 0; i < this->currLenght; i++)
	{
		if (this->history[i].date == month) count++;
	}
	return count;
}

int BrowserHistory::MonthWithMostEntries()
{
	//we save the amount of entries per month here
	int monthsCount[12];
	for (size_t i = 0; i < 12; i++)
	{
		monthsCount[i] = 0;
	}
	for (size_t i = 0; i < this->currLenght; i++)
	{
		monthsCount[this->history[i].date - 1]++;
	}
	int maxCount = 0;
	int indexOfMaxCount = 0;

	for (size_t i = 0; i < 12; i++)
	{
		if (monthsCount[i] > maxCount)
		{
			maxCount = monthsCount[i];
			indexOfMaxCount = i;
		}
	}

	return indexOfMaxCount + 1;


}

void BrowserHistory::PrintAll()
{
	if (this->currLenght != 0)
	{
		std::cout << "PRINTING ALL OF THE BROWSING DATA..." << std::endl;
		for (size_t i = 0; i < this->currLenght; i++)
		{
			std::cout << "Month: " << this->history[i].date << " URL: " << this->history[i].Url << std::endl;
		}
	}
	else
	{
		std::cout << "No Browsing data!" << std::endl;
	}
	
}

void BrowserHistory::AddNewHistoryEntry()
{
	if (this->IsFull())
	{
		std::cout << "There is no more memory!" << std::endl;
	}
	else
	{
		HistoryEntry newEntry;
		std::cout << "Enter the month of the entry: " << std::endl;
		std::cin >> newEntry.date;
		std::cout << "Enter the URL of the entry: " << std::endl;

		//clean the console before reading
		std::cin.ignore();

		int currMax = 128;

		//the length of the string
		int currLen = 0;

		char * url = new char[currMax];
		char currSymbol = std::cin.get();

		while (currSymbol != '\n')
		{
			//this way I guarantee that tha last terminating zero will be there
			if (currLen < currMax-1)
			{
				url[currLen] = currSymbol;
				currLen++;
			}
			else //in case 128 length is not enough
			{
				currMax *= 2;
				char * newUrl = new char[currMax];
				for (size_t i = 0; i < currLen; i++)
				{
					newUrl[i] = url[i];
				}

				delete[] url;

				url = newUrl;
			}
			currSymbol = std::cin.get();
		} 
		url[currLen] = '\0';
		currLen++;
		newEntry.Url = url;

		this->history[currLenght] = newEntry;
		this->currLenght++;
	}


}

void BrowserHistory::AddExistingEntry(const HistoryEntry & entry)
{
	if (this->IsFull())
	{
		std::cout << "There is no more memory!" << std::endl;
	}
	else
	{
		HistoryEntry newEntry;
		newEntry.date = entry.date;
		
		//length of the url of the entry we want to copy 
		int len = strlen(entry.Url) + 1;
		newEntry.Url = new char[len];
		memcpy(newEntry.Url, entry.Url, len);
		this->history[this->currLenght] = newEntry;
		this->currLenght++;
	}

}

void BrowserHistory::RemoveLastEntry()
{
	if (this->currLenght != 0)
	{
		currLenght--;

		//dealing with the dynamic memory used by the entry
		delete[] history[currLenght].Url;
	}
}
