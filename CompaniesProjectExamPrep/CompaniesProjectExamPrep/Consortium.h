#pragma once

#include"Company.h"
#include<iostream>
#include<vector>

class Consortium : public Company
{
private:
	void deleteThis();
	void copyFromOther(const Consortium& other);
	std::vector<Company*> subcontractors;

	int successfulProjects;
public:

	virtual double reliabilityRate() const;
	virtual bool perform(const char* project);
	virtual Company* newInstanceOf() const;

	Consortium();
	Consortium(const char* name);
	Consortium(const Consortium&);
	~Consortium();
	Consortium& operator= (const Consortium&);

	friend std::ostream& operator<<(std::ostream& os, const Consortium& con);

	void printStatus() const;

	void addSubcontractor(const Company& newComp);
	void deleteSubcontractor(const char * name);
};