#include "StateOwnedCompany.h"
using namespace std;

double StateOwnedCompany::reliabilityRate() const
{
	if (this->numberOfProjects == 0) return 0.0;

	int successfulProj = this->numberOfProjects % SUCCESS_RATE;

	return ((double)successfulProj )/ numberOfProjects;
}

bool StateOwnedCompany::perform(const char * project)
{
	this->numberOfProjects++;

	//success
	if (numberOfProjects % 20 == 0)
	{
		cout << project << " was successfuly completed by " << this->name << endl;
		return true;
	}

	cout << project << " was not completed by " << this->name << endl;
	return false;
}

Company * StateOwnedCompany::newInstanceOf() const
{
	return new StateOwnedCompany(*this);
}

StateOwnedCompany::StateOwnedCompany(const char * name) : Company(name)
{
}

std::ostream & operator<<(std::ostream & os, const StateOwnedCompany & comp)
{
	os << "state: " << comp.getName();
	return os;
}
