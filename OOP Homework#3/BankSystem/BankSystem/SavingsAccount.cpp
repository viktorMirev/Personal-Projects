#include "SavingsAccount.h"
#include<iostream>

using namespace std;

SavingsAccount::SavingsAccount(const char * iban, int ownerId, double amount, double interestRate) : Account(iban, ownerId, amount)
{
	this->interestRate = interestRate;
}

double SavingsAccount::getInterestRate() const
{
	return this->interestRate;
}

void SavingsAccount::deposit(double add)
{
	this->setBalance(this->getBalance() + add);
}

bool SavingsAccount::withdraw(double rem)
{
	//if there is not sufficient amount
	if (this->getBalance() < rem)
	{
		return false;
	}

	this->setBalance(this->getBalance() - rem);

	return true;
}

void SavingsAccount::display() const
{
	cout << endl
		<< "Account info" << endl
		<< "Account owner ID     : " << this->getOwnerId() << endl
		<< "Account IBAN         : " << this->getIban() << endl
		<< "Account balance      : " << this->getBalance() << endl
		<< "Account interest rate: " << this->interestRate << endl
		<< endl;
}

Account * SavingsAccount::newInstanceOf() const
{
	return new SavingsAccount(*this);
}
