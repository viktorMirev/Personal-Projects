#pragma once

#include"Account.h"

class SavingsAccount : public Account
{
public:
	SavingsAccount(const char * iban, int ownerId, double amount, double interestRate);

	double getInterestRate() const;
	void deposit(double add) override;
	bool withdraw(double rem) override;
	void display() const override;
	Account* newInstanceOf() const override;


private:
	double interestRate;

};