#include "Account.h"
#include<cstring>

Account::Account(const char * iban, int ownerId, double amount)
	: ownerId(ownerId), amount(amount)
{
	this->setIban(iban);
}

double Account::getBalance() const
{
	return this->amount;
}

const char * Account::getIban() const
{
	return this->iban;
}

int Account::getOwnerId() const
{
	return this->ownerId;
}

Account::Account() : amount(0.0), ownerId(0)
{
	this->setIban("No IBAN");
}

Account::Account(const Account & other)
{
	if (this != &other)
	{
		this->copyFromOther(other);
	}
}

Account::~Account()
{
	delete[] this->iban;
}

Account & Account::operator=(const Account & other)
{
	if (this != &other)
	{
		this->copyFromOther(other);
	}
	return *this;
}

void Account::setIban(const char * iban)
{
	if (this->iban) delete[] this->iban;

	if (iban)
	{
		int size = strlen(iban) + 1;
		this->iban = new char[size];
		memcpy(this->iban, iban, size);
	}
}

void Account::copyFromOther(const Account & other)
{
	this->setIban(other.iban);
	this->amount = other.amount;
	this->ownerId = other.ownerId;
}

void Account::setBalance(double newB)
{
	this->amount = newB;
}

