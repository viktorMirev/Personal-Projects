#pragma once

class Company
{
protected:
	char * name;
	void setName(const char*);
	void copyFromAnother(const Company&);
	int numberOfProjects;

public:
	virtual double reliabilityRate() const = 0;
	virtual bool perform(const char* project) = 0;
	virtual Company* newInstanceOf() const = 0;

	int numberOfExecutedProjects() const;
	const char* getName() const;

	Company();
	Company(const char* name);
	~Company();
	Company(const Company&);
	Company& operator=(const Company&);
};