#include"ElectricDevice.h"
#include<cstring>

ElectricDevice::ElectricDevice()
{
	this->name = nullptr;
	this->power = 0;
}

ElectricDevice::ElectricDevice(const char * name, int power)
{
	this->setName(name);
	this->power = power;
}

ElectricDevice::ElectricDevice(const ElectricDevice & other)
{
	this->setName(other.name);
	this->power = other.power;
}

ElectricDevice::~ElectricDevice()
{
	this->Delete();
}

int ElectricDevice::GetPower() const
{
	return this->power;
}

bool ElectricDevice::IsEqualTo(const ElectricDevice & other) const
{
	return strcmp(this->name, other.name);
}

bool ElectricDevice::IsName(const char  * name) const
{
	return strcmp(this->name,name) == 0;
}


ElectricDevice & ElectricDevice::operator=(const ElectricDevice & other)
{
	if (this != &other) 
	{
		this->setName(other.name);
		this->power = other.power;
	}

	return *this;
}

void ElectricDevice::setName(const char *name)
{
	if (this->name)
	{
		this->Delete();
		int size = strlen(name) + 1;
		memcpy(this->name, name, size);
	}
}

void ElectricDevice::Delete()
{
	delete[] this->name;
}
