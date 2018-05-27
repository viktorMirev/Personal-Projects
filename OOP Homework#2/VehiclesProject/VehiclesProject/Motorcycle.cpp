#include "Motorcycle.h"
#include<cstring>
#include<iostream>

using namespace std;

Motorcycle::Motorcycle() : Vehicle(), type(nullptr)
{
}
Motorcycle::Motorcycle(const Motorcycle & other) : Vehicle(other)
{
	this->setType(other.type);
}
Motorcycle::Motorcycle(const char * make, const char * model, const char * color, int year, double mileage, const char * type)
	: Vehicle(make, model, color, year, mileage)
{
	this->setType(type);
}
Motorcycle::~Motorcycle()
{
	this->DeleteAll();
}
Motorcycle & Motorcycle::operator=(const Motorcycle & other)
{
	if (this != &other)
	{
		this->CopyFromOther(other);
	}
	return *this;
}
const char * Motorcycle::GetType() const
{
	return this->type;
}
void Motorcycle::Details() const
{
	cout << "Make: " << ((this->GetMake() == nullptr) ? ("no make") : (this->GetMake())) << endl
		<< "Model: " << ((this->GetModel() == nullptr) ? ("no model") : (this->GetModel())) << endl
		<< "Color: " << ((this->GetColor() == nullptr) ? ("no color") : (this->GetColor())) << endl
		<< "Mileage: " << this->GetMileage() << endl
		<< "Year: " << this->GetYear() << endl
		<< "Type: " << ((this->GetType() == nullptr) ? ("no type") : (this->type)) << endl;
}
void Motorcycle::setType(const char * type)
{
	if (this->type)
	{
		delete[] this->type;
	}

	if (type)
	{
		int size = strlen(type) + 1;
		this->type = new char(size);
		memcpy(this->type, type, size);
	}
}


void Motorcycle::CopyFromOtherMotorcycle(const Motorcycle & other)
{
	CopyFromOther(other);
	this->setType(other.type);
}

void Motorcycle::DeleteAll()
{
	Delete();
	delete[] this->type;
}
