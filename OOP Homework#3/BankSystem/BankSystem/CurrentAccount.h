#pragma once
#include"Account.h"

class CurrentAccount : public Account
{
public:
	CurrentAccount(const char * iban, int ownerId, double amount);

	void deposit(double add) override;
	bool withdraw(double rem) override;
	void display() const override;
    Account* newInstanceOf() const override;
};