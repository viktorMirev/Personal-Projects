#pragma once

class Account
{
public:
	Account(const char * iban, int ownerId, double amount);

	//it is idiotic to be pure virtual but.. 
	//deposit is the same for the three other classes..
	virtual void deposit(double add) = 0;
	virtual bool withdraw(double rem) = 0;
	virtual void display() const = 0;
	virtual Account* newInstanceOf() const = 0;

	//getters
	double getBalance() const;
	const char * getIban() const;
	int getOwnerId() const;
	//the big four ( needed as it has dynamic data)

	Account();
	Account(const Account& other);
	~Account();
	Account & operator=(const Account & other);


private:

	char * iban;
	int ownerId;
	double amount;

	//setters ( private by deff)
	void setIban(const char * iban);

	//
	void copyFromOther(const Account& other);


protected:
	void setBalance(double newB);

};