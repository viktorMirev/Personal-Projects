#pragma once

class Product
{
public:
	//Constructor
	Product(char* brand, char * model, char * size, char * color, double price, int count);

	//Copy Constructor
	Product(const Product& other);

	//Destructor
	~Product();

	//Operator =
	void operator=(const Product& other);

	//Printing function
	void Print() const;

	//Selectors

	int GetSku() const;

	//Mutators


	//Only the price and the count can be changed 
	//It is not possible to alter the size or the color of a T-shirt
	//If you have to change it , it is another model so you have to delete 
	//the current one and create new

	//Price change
	void SetPrice(double price);

	//Count change
	void SetCount(int count);

private:
	static int skuProvider;

	//deletes all the dynamic data
	void Delete();


	//copies from other product
	void CopyFromOther(const Product& other);

	//Unique product number
	int SKU;

	//Brand of the T-shirt
	char * brand;

	//The name of the Model
	char * model;

	//The size of the T-Shirt can be xs,s,m,l,xl
	char * size;

	//The color of the T-shirt
	char * color;

	//The price of the T-shirt
	double price;

	//The number of T-shirts of this model the store keeps in storage
	int count;

};
