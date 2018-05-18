#pragma once

class ElectricDevice
{
public:
	ElectricDevice();
	ElectricDevice(const char* , int);
	ElectricDevice(const ElectricDevice&);

	~ElectricDevice();
	int GetPower() const;
	bool IsEqualTo(const ElectricDevice &) const;
	bool IsName(const char*) const;
	ElectricDevice& operator=(const ElectricDevice&);


private:
	int power;
	char * name;
	void setName(const char *);
	void Delete();
};