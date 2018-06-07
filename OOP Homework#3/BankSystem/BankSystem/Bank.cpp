#include "Bank.h"
#include<cstring>
#include<iostream>

using namespace std;

Bank::Bank(const char * name, const char * address)
{
	this->setName(name);
	this->setAddress(address);
}

Bank::Bank()
{
	this->setAddress("No address");
	this->setName("No name");
}

Bank::Bank(const Bank & other)
{
	this->copyFromOther(other);
}

Bank::~Bank()
{
	delete[] name;
	delete[] address;

	this->deleteAccounts();
	this->deleteCustomers();
}

Bank & Bank::operator=(const Bank & other)
{
	if (this != &other)
	{
		this->copyFromOther(other);
	}

	return *this;
}

const char * Bank::getName() const
{
	return this->name;
}

const char * Bank::getAddress() const
{
	return this->address;
}

void Bank::withdrawFromAccount(const char * iban, double amount)
{
	int index = this->findAccount(iban);
	if (index >= 0)
	{
		if (!accounts[index]->withdraw(amount))
		{
			cout << endl
				<< "No enough!" << endl
				<< endl;
		}
	}
	else
	{
		cout << endl
			<< "No such account!" << endl
			<< endl;
	}
}

void Bank::depositToAccount(const char * iban, double amount)
{
	int index = this->findAccount(iban);
	if (index >= 0)
	{
		accounts[index]->deposit(amount);
	}
	else
	{
		cout << endl
			<< "No such account!" << endl
			<< endl;
	}
}

void Bank::addCustomer(int custId, const char * custName, const char * custAddress)
{
	if (this->findCustomer(custId) < 0)
	{
		Customer * newCustomer = new Customer(custId, custName, custAddress);
		this->customers.push_back(newCustomer);
	}
	else
	{
		cout << endl
			<< "ID is already in use!" << endl
			<< endl;
	}
}

void Bank::deleteCustomer(int custId)
{
	int index = this->findCustomer(custId);
	if (index >= 0)
	{
		this->deleteCustomerByIndex(index);

		for (int i = 0; i < accounts.size(); )
		{
			if (accounts[i]->getOwnerId() == custId)
			{
				this->deleteAccountByIndex(i);
			}
			else 
			{
				i++;
			}
		}

	}
	else
	{
		cout << endl
			<< "No such customer!" << endl
			<< endl;
	}

}

void Bank::deleteCustomerByIndex(int index)
{
	delete customers[index];
	customers.erase(customers.begin() + index);
}

void Bank::deleteAccountByIndex(int index)
{
	delete accounts[index];
	accounts.erase(accounts.begin() + index);
}

void Bank::addAccount(char accountType, const char * iban, int ownerId, double amount)
{
	if (this->findCustomer(ownerId)>=0 && this->findAccount(iban) == -1)
	{
		Account * newAcc = nullptr;
		switch (accountType)
		{
		case 'C':
			//current account
		    newAcc = new CurrentAccount(iban, ownerId, amount);
			break;
		case 'S':
			//saving account
			newAcc = new SavingsAccount(iban, ownerId, amount, DEFAULT_INTEREST_RATE);
			break;
		case 'P':
			//privilege account
			newAcc = new PrivilegeAccount(iban, ownerId, amount, DEFAULT_OVERDRAFT);
			break;
		default :
			cout << endl
				<< "WRONG! Enter correct type" << endl
				<< endl;
		}
		if (newAcc)
		{
			accounts.push_back(newAcc);
		}
	}
	else
	{
		cout << endl
			<< "Unable to create account(not an actual customer or used iban)!" << endl
			<< endl;
	}
}

void Bank::deleteAccount(const char * iban)
{
	int index = this->findAccount(iban);
	if (index >= 0)
	{
		this->deleteAccountByIndex(index);
	}
}

void Bank::listAccounts() const
{
	cout << endl
		<< "ALL ACCOUNTS INFO!" << endl
		<< endl;

	if (accounts.size() == 0)
	{
		cout << "No accounts!" << endl;
		return;
	}

	for (size_t i = 0; i < accounts.size(); i++)
	{
		accounts[i]->display();
	}
}

void Bank::listCustomers() const
{
	cout << endl
		<< "INFO ABOUT CUSTOMERS" << endl
		<< endl;
	if (customers.size() == 0)
	{
		cout << endl
			<< "No Customers!" << endl
			<< endl;
		return;
	}
	for (size_t i = 0; i < customers.size(); i++)
	{
		customers[i]->display();
	}
}

void Bank::listCustomerAccount(int custId) const
{
	int index = findCustomer(custId);
	if (index < 0) 
	{
		cout << endl
			<< "No customer with such ID" << endl
			<< endl;
		return;
	}

	cout << endl
		<< "Info about the accounts of: " << customers[index]->getName() << endl
		<< endl;

	for (size_t i = 0; i < accounts.size(); i++)
	{
		if (accounts[i]->getOwnerId() == custId)
		{
			accounts[i]->display();
		}
	}
}

void Bank::transfer(const char * fromIBAN, const char * toIBAN, double amount)
{
	int fromIndex = this->findAccount(fromIBAN);
	int toIndex = this->findAccount(toIBAN);

	//account validation;
	if (fromIndex < 0 || toIndex < 0)
	{
		cout << endl
			<< "Incorrect Accounts" << endl
			<< endl;
		return;
	}

	if (this->accounts[fromIndex]->withdraw(amount))
	{
		this->accounts[toIndex]->deposit(amount);
	}
	else
	{
		cout << endl
			<< "Insufficient amount" << endl
			<< endl;
	}

}

void Bank::display() const
{
	cout << "Bank Name          : " << this->name << endl
		<< "Bank Address       : " << this->address << endl
		<< "Number of customers: " << this->customers.size() << endl
		<< "Number of accounts : " << this->accounts.size() << endl;
}

void Bank::setName(const char * name)
{
	if (this->name) delete[] this->name;

	if (name)
	{
		int size = strlen(name) + 1;
		this->name = new char[size];
		memcpy(this->name, name, size);
	}
}

void Bank::setAddress(const char * address)
{
	if (this->address) delete[] this->address;

	if (address)
	{
		int size = strlen(address) + 1;
		this->address = new char[size];
		memcpy(this->address, address, size);
	}
}

void Bank::copyFromOther(const Bank & other)
{
	this->setName(other.name);
	this->setAddress(other.address);

	//clear customers
	this->deleteCustomers();

	//copy customers
	this->customers = vector<Customer*>(other.customers.size());
	for (size_t i = 0; i < other.customers.size(); i++)
	{
		this->customers.push_back(new Customer(*other.customers[i]));
	}

	//clear accounts
	this->deleteAccounts();

	//copy accounts
	this->accounts = vector<Account*>(other.accounts.size());
	for (size_t i = 0; i < other.accounts.size(); i++)
	{
		this->accounts.push_back(other.accounts[i]->newInstanceOf());
	}
}


void Bank::deleteCustomers()
{
	for (size_t i = 0; i < this->customers.size(); i++)
	{
		delete customers[i];
	}
}

void Bank::deleteAccounts()
{
	for (size_t i = 0; i < this->accounts.size(); i++)
	{
		delete accounts[i];
	}
}

int Bank::findCustomer(int custId) const
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (customers[i]->getId() == custId)
		{
			return i;
		}
	}
	return -1;
}

int Bank::findAccount(const char * iban) const
{
	for (int i = 0; i < accounts.size(); i++)
	{
		if (strcmp(accounts[i]->getIban(), iban) == 0)
		{
			return i;
		}
	}
	return -1;
}


