#include "Truck.h"
#include<iostream>

using namespace std;

Truck::Truck() : Vehicle()//, size(0)
{
}



Truck::Truck(const char * make, const char * model, const char * color, int year, double mileage, double size)
	: Vehicle(make,model,color,year,mileage), size(size)
{
}

Truck::Truck(const Truck & other) : Vehicle(other)
{
	this->size = other.size;
}

Truck & Truck::operator=(const Truck & other)
{
	Vehicle::operator=(other);
	this->size = other.size;
	return *this;
}

void Truck::Details() const
{

	cout << "Make: " << ((this->GetMake() == nullptr) ? ("no make") : (this->GetMake())) << endl
		<< "Model: " << ((this->GetModel() == nullptr) ? ("no model") : (this->GetModel())) << endl
		<< "Color: " << ((this->GetColor() == nullptr) ? ("no color") : (this->GetColor())) << endl
		<< "Mileage: " << this->GetMileage() << endl
		<< "Year: " << this->GetYear() << endl
		<< "Size: " << this->size << endl;
	    
}
