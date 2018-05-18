#include "ElectricNet.h"
#include<iostream>

ElectricNet::ElectricNet()
{
	this->maxPower = 1;
	this->currConsumption = 0;
}

ElectricNet::ElectricNet(const ElectricNet&other)
{
	this->allDevices = other.allDevices;
	this->maxPower = other.maxPower;
	this->currConsumption = other.currConsumption;
}

ElectricNet & ElectricNet::operator+(const ElectricDevice & newDevice)
{
	ElectricNet* newNet = new ElectricNet(*this);
	if (newNet->currConsumption + newDevice.GetPower() <= newNet->maxPower) 
	{
		newNet->allDevices.Add(new ElectricDevice(newDevice));
		newNet->currConsumption += newDevice.GetPower();
	}
	else 
	{
		std::cout << "Not enough power capabilities!" << std::endl;
		return *this;
	}
	return *newNet;
}

ElectricNet & ElectricNet::operator+=(const ElectricDevice & newDevice)
{
	if (this->currConsumption + newDevice.GetPower() <= this->maxPower)
	{
		this->allDevices.Add(new ElectricDevice(newDevice));
		this->currConsumption += newDevice.GetPower();
	}
	else
	{
		std::cout << "Not enough power capabilities!" << std::endl;
		
	}
	return *this;
}

ElectricNet & ElectricNet::operator-(const ElectricDevice & toBeRemoved)
{
	ElectricNet* newNet = new ElectricNet(*this);

	for (int i = 0; i < newNet->allDevices.Size(); i++)
	{
		if (newNet->allDevices[i]->IsEqualTo(toBeRemoved))
		{
			newNet->currConsumption -= toBeRemoved.GetPower();
			newNet->allDevices.RemoveAt(i);
			break;
		}
	}

	return *newNet;
}

ElectricNet ElectricNet::operator-=(const ElectricDevice & toBeRemoved)
{
	for (int i = 0; i < this->allDevices.Size(); i++)
	{
		if (this->allDevices[i]->IsEqualTo(toBeRemoved))
		{
			this->currConsumption -= toBeRemoved.GetPower();
			this->allDevices.RemoveAt(i);
			break;
		}
	}

	return *this;
}

void ElectricNet::operator++()
{
	this->maxPower*= 2;
}

void ElectricNet::operator--()
{
	if (this->currConsumption <= this->maxPower / 2)
	{
		this->maxPower /= 2;
	}
}

bool ElectricNet::operator!()
{
	return this->allDevices.Size()>0;
}

ElectricDevice & ElectricNet::operator[](const char * name)
{
	for (int i = 0; i < this->allDevices.Size(); i++)
	{
		if (allDevices[i]->IsName(name))
		{
			return *allDevices[i];
		}
	}
	std::cout << "NO SUCH DEVICE, returning empty electric device!"<<std::endl;

	return * (new ElectricDevice());
}

