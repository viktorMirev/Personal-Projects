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

void Truck::Details() const
{

	cout << "Make: " << this->GetMake() << endl
		<< "Model: " << this->GetModel() << endl
		<< "Color: " << this->GetColor() << endl
		<< "Mileage: " << this->GetMileage() << endl
		<< "Year: " << this->GetYear() << endl
		<< "Size: " << this->size << endl;
	    
}
