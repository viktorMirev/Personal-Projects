#pragma once
#include"Company.h"
#include<iostream>
class PrivateCompany : public Company
{
private:
	int failure_rate;

public:
	virtual double reliabilityRate() const;
	virtual bool perform(const char* project);
	virtual Company* newInstanceOf() const;


	PrivateCompany();
	PrivateCompany(const char* name, int failRate);

	friend std::ostream& operator<<(std::ostream& os, const PrivateCompany& comp);


};