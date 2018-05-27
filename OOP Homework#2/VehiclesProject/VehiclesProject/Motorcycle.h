#pragma once

#include"Vehicle.h"

class Motorcycle : public Vehicle
{
public:
	Motorcycle();
	Motorcycle(const Motorcycle&);
	Motorcycle(const char * make, const char * model, const char * color, int year, double mileage, const char * type);
	~Motorcycle();
	Motorcycle & operator=(const Motorcycle&);
	const char * GetType() const;

	virtual void Details() const;

private:
	char * type;
	void setType(const char*);
	void CopyFromOtherMotorcycle(const Motorcycle &); 
	void DeleteAll();
};
