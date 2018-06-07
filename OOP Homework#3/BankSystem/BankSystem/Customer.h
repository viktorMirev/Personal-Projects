#pragma once

class Customer
{
public :
	Customer(int id, const char * name, const char * address);
	int getId() const;

	//getters
	const char * getName() const;
	const char * getAddress() const;
	void display();

	//the big four ( since we have dynamic)
	Customer();
	Customer(const Customer&);
	~Customer();
	Customer& operator= (const Customer &);

private:
	int id;
	char * name;
	char * address;

	//setters private by default
	void setName(const char * name);
	void setAddress(const char * address);

	//
	void copyFromOther(const Customer&);
};