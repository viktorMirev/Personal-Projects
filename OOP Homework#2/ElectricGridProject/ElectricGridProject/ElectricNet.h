#pragma once
#include"ElectricDevice.h"
#include"Vector.h"

class ElectricNet
{
public:
	ElectricNet();
	ElectricNet(const ElectricNet&);
	ElectricNet& operator+(const ElectricDevice&);
	ElectricNet& operator+=(const ElectricDevice&);
	ElectricNet& operator-(const ElectricDevice&);
	ElectricNet operator-=(const ElectricDevice&);
	void operator++();
	void operator--();
	bool operator!();
	ElectricDevice& operator[](const char * name);



private:
	int maxPower;
	int currConsumption;
	Vector<ElectricDevice*> allDevices;
};