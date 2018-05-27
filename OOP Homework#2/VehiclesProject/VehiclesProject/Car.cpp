#include"Car.h"
#include<iostream>

using namespace std;

Car::Car() : Vehicle()
{
}

Car::Car(const char * make, const char * model, const char * color, int year, double mileage)
	: Vehicle(make,model,color,year,mileage)
{
}

Car::Car(const Car & other) : Vehicle(other)
{
}

Car & Car::operator=(const Car & other)
{
	if (this != &other)
	{
		Vehicle ::operator=(other);
	}
	return *this;
}

void Car::Details() const
{
	cout <<"Make: "<< this->GetMake() << endl
		<< "Model: "<<this->GetModel() << endl
		<< "Color: "<<this->GetColor() << endl
		<< "Mileage: "<<this->GetMileage() << endl
		<< "Year: "<<this->GetYear() << endl;
	
}
