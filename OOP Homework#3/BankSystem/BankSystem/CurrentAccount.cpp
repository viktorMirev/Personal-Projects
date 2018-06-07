#include "CurrentAccount.h"
#include<iostream>

using namespace std;

CurrentAccount::CurrentAccount(const char * iban, int ownerId, double amount) : Account(iban, ownerId, amount)
{
}

void CurrentAccount::deposit(double add)
{
	this->setBalance(this->getBalance() + add);
}

bool CurrentAccount::withdraw(double rem)
{
	//if there is not sufficient amount
	if (this->getBalance() < rem)
	{
		return false;
	}

	this->setBalance(this->getBalance() - rem);

	return true;
}

void CurrentAccount::display() const
{
	cout << endl
		<< "Account info" << endl
		<< "Account owner ID : " << this->getOwnerId() << endl
		<< "Account IBAN     : " << this->getIban() << endl
		<< "Account balance  : " << this->getBalance() << endl
		<< endl;
}

Account * CurrentAccount::newInstanceOf() const
{
	return new CurrentAccount(*this);
}
