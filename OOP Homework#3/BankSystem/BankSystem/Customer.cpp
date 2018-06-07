#include "Customer.h"
#include<cstring>
#include<iostream>

using namespace std;

void Customer::setName(const char * name)
{
	if (this->name) delete[] this->name;

	if (name)
	{
		int size = strlen(name) + 1;
		this->name = new char[size];
		memcpy(this->name, name, size);
	}
}

void Customer::setAddress(const char * address)
{
	if (this->address) delete[] this->address;

	if (address)
	{
		int size = strlen(address) + 1;
		this->address = new char[size];
		memcpy(this->address, address, size);
	}
}

void Customer::copyFromOther(const Customer & other)
{
	this->setAddress(other.address);
	this->setName(other.name);
	this->id = other.id;
}

Customer::Customer(int id, const char * name, const char * address) 
	: id(id)
{
	this->setAddress(address);
	this->setName(name);
}

int Customer::getId() const
{
	return this->id;
}

const char * Customer::getName() const
{
	return this->name;
}

const char * Customer::getAddress() const
{
	return this->address;
}

void Customer::display()
{
	cout << endl
	     << "Customer ID:      " << id << endl
	     << "Customer Name:    " << name << endl
	     << "Customer Address: " << address << endl
	     << endl;
}

Customer::Customer() : id(0)
{
	this->setAddress("No Address");
	this->setName("No Name");
}

Customer::Customer(const Customer & other)
{
	this->copyFromOther(other);
}

Customer::~Customer()
{
	delete[] name;
	delete[] address;
}

Customer & Customer::operator=(const Customer & other)
{
	if (this != &other)
	{
		this->copyFromOther(other);
	}
	return *this;
}
