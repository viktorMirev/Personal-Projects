#include "PrivilegeAccount.h"
#include<iostream>

using namespace std; 

PrivilegeAccount::PrivilegeAccount(const char * iban, int ownerId, double amount, double overdraft)
	: Account(iban,ownerId,amount)
{
	this->overdraft = overdraft;
}

double PrivilegeAccount::getOverdraft() const
{
	return this->overdraft;
}

void PrivilegeAccount::deposit(double add)
{
	this->setBalance(this->getBalance() + add);
}

bool PrivilegeAccount::withdraw(double rem)
{
	//if there is not sufficient amount
	if (this->getBalance()  + overdraft < rem)
	{
		return false;
	}

	this->setBalance(this->getBalance() - rem);

	return true;
}

void PrivilegeAccount::display() const
{
	cout << endl
		<< "Account info" << endl
		<< "Account owner ID  : " << this->getOwnerId() << endl
		<< "Account IBAN      : " << this->getIban() << endl
		<< "Account balance   : " << this->getBalance() << endl
		<< "Possible overdraft: " << overdraft << endl
		<< endl;
}

Account * PrivilegeAccount::newInstanceOf() const
{
	return new PrivilegeAccount(*this);
}
