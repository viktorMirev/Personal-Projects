#include "Vehicle.h"
#include<cstring>

Vehicle::Vehicle(): make(nullptr),model(nullptr),color(nullptr),year(0),mileage(0.0)
{
}

Vehicle::Vehicle(const char * make, const char * model, const char * color, int year, double mileage) : year(year), mileage(mileage)
{
	this->SetMake(make);
	this->SetModel(model);
	this->SetColor(color);
}

Vehicle::Vehicle(const Vehicle & other)
{
	this->CopyFromOther(other);
}

Vehicle & Vehicle::operator=(const Vehicle & other)
{
	if (this != &other)
	{
		//this->Delete();
		this->CopyFromOther(other);
	}

	return *this;
}

Vehicle::~Vehicle()
{
	this->Delete();
}

void Vehicle::Details() const
{
}

int Vehicle::GetYear() const
{
	return this->year;
}

double Vehicle::GetMileage() const
{
	return this->mileage;
}

const char * Vehicle::GetMake() const
{
	return this->make;
}

const char * Vehicle::GetModel() const
{
	return model;
}

const char * Vehicle::GetColor() const
{
	return color;
}

void Vehicle::SetYear(int y)
{
	this->year = y;
}

void Vehicle::SetMileage(double m)
{
	this->mileage = m;
}

void Vehicle::SetMake(const char * make)
{
	if (this->make) delete[] this->make;


	if (make)
	{
		int size = strlen(make) + 1;

		this->make = new char[size];

		memcpy(this->make, make, size);
	}
	
}

void Vehicle::SetModel(const char * model)
{
	if (this->model) delete[] this->model;

	if (model)
	{
		int size = strlen(model) + 1;

		this->model = new char[size];

		memcpy(this->model, model, size);
	}

	
}

void Vehicle::SetColor(const char * color)
{
	if (this->color) delete[] this->color;

	if (color)
	{
		int size = strlen(color) + 1;

		this->color = new char[size];

		memcpy(this->color, color, size);
	}

	
}

void Vehicle::Delete()
{
	delete[] this->make;
	delete[] this->model;
	delete[] this->color;
}

void Vehicle::CopyFromOther(const Vehicle & other)
{
	this->SetColor(other.color);
	this->SetMake(other.make);
	this->SetMileage(other.mileage);
	this->SetModel(other.model);
	this->SetYear(other.year);
}

