#pragma once
#include"Account.h"

class PrivilegeAccount :public Account
{
public:
	PrivilegeAccount(const char * iban, int ownerId, double amount, double overdraft);
	double getOverdraft() const;
	void deposit(double add) override;
	bool withdraw(double rem) override;
	void display() const override;
	Account* newInstanceOf() const override;

private:
	double overdraft;

};