#include "Company.h"
#include<cstring>

void Company::setName(const char * name)
{
	if (this->name) delete[] this->name;

	if (name)
	{
		int size = strlen(name) + 1;
		this->name = new char[size];
		memcpy(this->name, name, size);
	}
}

void Company::copyFromAnother(const Company & other)
{
	this->setName(other.name);
	numberOfProjects = other.numberOfProjects;
}

int Company::numberOfExecutedProjects() const
{
	return numberOfProjects;
}

const char * Company::getName() const
{
	return this->name;
}

Company::Company() : name(nullptr), numberOfProjects(0)
{
}

Company::Company(const char * name) : numberOfProjects(0)
{
	this->name = nullptr;
	this->setName(name);
}

Company::~Company()
{
	delete[] this->name;
}

Company::Company(const Company & other)
{
	this->name = nullptr;
	copyFromAnother(other);
}

Company & Company::operator=(const Company &other)
{
	if (this != &other)
	{
		this->copyFromAnother(other);
	}
	return *this;
}
