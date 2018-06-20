#include "Consortium.h"
#include<cstring>

using namespace std;

void Consortium::deleteThis()
{

	for (size_t i = 0; i < subcontractors.size(); i++)
	{
		delete subcontractors[i];
	}
}

void Consortium::copyFromOther(const Consortium & other)
{
	this->successfulProjects = other.successfulProjects;
	subcontractors = std::vector<Company*>(other.subcontractors.size());

	for (size_t i = 0; i < subcontractors.size(); i++)
	{
		subcontractors[i] = other.subcontractors[i]->newInstanceOf();
	}
}

double Consortium::reliabilityRate() const
{
	if (numberOfProjects == 0) return 0.0;

	return (double)successfulProjects / this->numberOfProjects;
}

bool Consortium::perform(const char * project)
{
	this->numberOfProjects++;
	if (subcontractors.size() == 0)
	{
		cout << "No subcontractors" << endl;
		return false;
	}

	//search for the noobs
	int min = subcontractors[0]->numberOfExecutedProjects();
	int minIndex = 0;

	for (size_t i = 1; i < subcontractors.size(); i++)
	{
		if (subcontractors[i]->numberOfExecutedProjects() < min)
		{
			min = subcontractors[i]->numberOfExecutedProjects();
			minIndex = i;
		}
	}
	
	if (subcontractors[minIndex]->perform(project))
	{
		successfulProjects++;
		return true;
	}
	return false;
}

Company * Consortium::newInstanceOf() const
{
	return new Consortium(*this);
}

Consortium::Consortium() : Company(), successfulProjects(0)
{
}

Consortium::Consortium(const char * name) : Company(name), successfulProjects(0)
{
}

Consortium::Consortium(const Consortium & other) : Company(other)
{
	this->deleteThis();
	this->copyFromOther(other);
}

Consortium::~Consortium()
{
	this->deleteThis();
}

Consortium & Consortium::operator=(const Consortium & other)
{
	if (this != &other)
	{
		this->deleteThis();
		Company::copyFromAnother(other);
		this->copyFromAnother(other);
	}
	return *this;
}

void Consortium::printStatus() const
{
	for (size_t i = 0; i < subcontractors.size(); i++)
	{
		cout << i << "." << subcontractors[i]->getName() << " reliability rate: " << subcontractors[i]->reliabilityRate() << endl;
	}
}

void Consortium::addSubcontractor(const Company & newComp)
{
	this->subcontractors.push_back(newComp.newInstanceOf());
}

void Consortium::deleteSubcontractor(const char * name)
{
	for (size_t i = 0; i < subcontractors.size(); i++)
	{
		if (strcmp(subcontractors[i]->getName(), name) == 0)
		{
			delete this->subcontractors[i];
			subcontractors.erase(subcontractors.begin() + i);
			return;
		}
	}
}

std::ostream & operator<<(std::ostream & os, const Consortium & con)
{
	os << "consortium: " << con.subcontractors.size() << " " << con.getName();
	return os;
}
