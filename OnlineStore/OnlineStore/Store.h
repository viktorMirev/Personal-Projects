#pragma once
#include"Product.h"

class Store
{
public:
	//constructor
	Store();

	//destructor
	~Store();



	//Displays information about all of the products
	void PrintAll() const;

	//Adds new product
	void AddNewProduct(const Product& other);

	//Deletes specific product (sku needed)
	void DeleteProduct(int sku);

	//Changes the price of a specific product
	void ChangePriceOf(int sku,double price);

	//Changes the count of a specific product
	void ChangeCountOf(int sku, int count);

private:
	//the lenght of the array
	int currentMax;

	//the current number of products
	int currentCount;

	Product ** allProducts;

	//deletes the array with products
	void Delete();

	//returns the index of product with specifix sku
	int FindSku(int sku);
};
