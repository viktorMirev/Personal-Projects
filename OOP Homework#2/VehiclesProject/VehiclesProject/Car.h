#pragma once

#include"Vehicle.h"

class Car : public Vehicle
{
public:
	Car();
	Car(const char* make, const char* model, const char* color, int year, double mileage);
	Car(const Car &);
	Car & operator=(const Car &);
	virtual void Details() const;
};