#pragma once
#include"Company.h"
#include<iostream>

class  StateOwnedCompany : public Company
{
private:
	int const SUCCESS_RATE = 20;

public:
	virtual double reliabilityRate() const;
	virtual bool perform(const char* project);
	virtual Company* newInstanceOf() const;
    friend std::ostream& operator<<(std::ostream&, const StateOwnedCompany&);

	StateOwnedCompany(const char* name);
};