#include<iostream>
#include"Product.h"

int Product::skuProvider = 0;

Product::Product(char * brand, char * model, char * size, char * color, double price, int count)
{
	//it is static so it provides different id s all the time
	this->SKU = this->skuProvider++;

	this->brand = brand;
	this->model = model;
	this->size = size;
	this->color = color;
	this->price = price;
	this->count = count;
}

Product::Product(const Product & other)
{
	this->CopyFromOther(other);
}

Product::~Product()
{
	this->Delete();
}

void Product::operator=(const Product & other)
{
	this->Delete();
	CopyFromOther(other);
}

void Product::Print() const
{
	std::cout << "FULL PRODUCT DESCRIPTION:" << std::endl;
	std::cout << std::endl;
	std::cout << "SKU: " << this->SKU << std::endl;
	std::cout << "brand: " << this->brand<< std::endl;
	std::cout << "model: " << this->model << std::endl;
	std::cout << "size: " << this->size << std::endl;
	std::cout << "color: " << this->color << std::endl;
	std::cout << "price: " << this->price << std::endl;
	std::cout << "count: " << this->count << std::endl;
	std::cout << std::endl;
}

int Product::GetSku() const
{
	return this->SKU;
}

void Product::SetPrice(double price)
{
	this->price = price;
}

void Product::SetCount(int count)
{
	this->count = count;
}

void Product::Delete()
{
	delete[] this->brand;

	delete[] this->model;

	delete[] this->size;

	delete[] this->color;
}

void Product::CopyFromOther(const Product& other)
{
	this->SKU = this->skuProvider++;

	int len = strlen(other.brand) + 1;
	this->brand = new char[len];
	memcpy(this->brand, other.brand, len);

	len = strlen(other.model) + 1;
	this->model = new char[len];
	memcpy(this->model, other.model, len);

	len = strlen(other.size) + 1;
	this->size = new char[len];
	memcpy(this->size, other.size, len);

	len = strlen(other.color) + 1;
	this->color = new char[len];
	memcpy(this->color, other.color, len);

	this->price = other.price;
	this->count = other.count;
}
