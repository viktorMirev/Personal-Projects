#pragma once

#include"Vehicle.h"

class Truck : public Vehicle
{
public:
	Truck();
	Truck(const char * make, const char * model, const char * color, int year, double mileage, double size);
	virtual void Details() const;

private:
	double size;
};

