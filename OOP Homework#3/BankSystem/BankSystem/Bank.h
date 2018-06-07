#pragma once
#include<vector>
#include"Account.h"
#include"Customer.h"
#include"CurrentAccount.h"
#include"PrivilegeAccount.h"
#include"SavingsAccount.h"
using namespace std;

class Bank
{

public:
	Bank(const char * name, const char * address);

	//the big four (we have dynamic memory)
	Bank();
	Bank(const Bank & other);
	~Bank();
	Bank & operator=(const Bank & other);
	//

	//getters
	const char * getName() const;
	const char * getAddress() const;

	//
	void withdrawFromAccount(const char * iban, double amount);

	void depositToAccount(const char * iban, double amount);

	//
	void addCustomer(int custId, const char * custName, const char * custAddress);
	void deleteCustomer(int custId);
	//if problem display error
	void addAccount(char accountType,const char * iban, int ownerId, double amount);
	void deleteAccount(const char * iban);
	
	//display
	void listAccounts() const;
	void listCustomers() const;

	//all accounts of this customer
	void listCustomerAccount(int custId) const;

	void transfer(const char * fromIBAN, const char * toIBAN, double amount);

	//basic info + number of customers
	void display() const;
private:
	char * name;
	char * address;
	const double DEFAULT_INTEREST_RATE = 5.5;
	const double DEFAULT_OVERDRAFT = 1500.0;
	//setters
	void setName(const char * name);
	void setAddress(const char * address);

	vector<Customer*> customers;
	vector<Account*> accounts;
	void copyFromOther(const Bank & other);

	void deleteCustomers();
	void deleteAccounts();

	int findCustomer(int custId) const;
	int findAccount(const char * iban) const;
	
	void deleteCustomerByIndex(int index);
	void deleteAccountByIndex(int index);
};