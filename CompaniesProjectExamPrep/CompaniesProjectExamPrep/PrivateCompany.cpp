#include "PrivateCompany.h"

using namespace std;

double PrivateCompany::reliabilityRate() const
{
	if (this->numberOfProjects == 0) return 0.0;

	int fails = this->numberOfProjects%failure_rate;
	return ((double)(this->numberOfProjects - fails) )/ numberOfProjects;
}

bool PrivateCompany::perform(const char * project)
{
	this->numberOfProjects++;

	//failure
	if (numberOfProjects % failure_rate == 0)
	{
		cout << project << " was not completed by " << this->name << endl;
		return false;
	}

	cout << project << " was successfuly completed by " << this->name << endl;
	return true;
}

Company * PrivateCompany::newInstanceOf() const
{
	return new PrivateCompany(*this);
}

PrivateCompany::PrivateCompany() : Company(), failure_rate(0)
{
}

PrivateCompany::PrivateCompany(const char * name, int failRate) : Company(name), failure_rate(failRate)
{
}

std::ostream & operator<<(std::ostream & os, const PrivateCompany & comp)
{
	os << "private: " << comp.failure_rate << " " << comp.getName();
	return os;
}
