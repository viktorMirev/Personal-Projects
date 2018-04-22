#include<iostream>

#include"Product.h"
#include"Store.h"




//used to read string from the console
char * CStringReader();

//works as a menu selector
int MenuSelector(char symbol, Store * myStore);

//helps with the creation of the new Products
Product * CreateNewProductFromConsole();

void PrintMenu();



int main()
{
	Store * myStore = new Store();

	//if Q is pressed it quits
	int operationResult = 0;

	while (operationResult != -1)
	{
		PrintMenu();
		char symbol;
		std::cin >> symbol;
		std::cin.ignore();
		operationResult = MenuSelector(symbol,myStore);
		std::cout << "Press any key to continue..." << std::endl;
		std::cin.get();
	}
	return 0;
}

char * CStringReader()
{
	int currMax = 128;

	//the length of the string
	int currLen = 0;

	char * cString = new char[currMax];
	char currSymbol = std::cin.get();

	while (currSymbol != '\n')
	{
		//this way I guarantee that tha last terminating zero will be there
		if (currLen < currMax - 1)
		{
			cString[currLen] = currSymbol;
			currLen++;
		}
		else //in case 128 length is not enough
		{
			currMax *= 2;
			char * new_cString = new char[currMax];
			for (size_t i = 0; i < currLen; i++)
			{
				new_cString[i] = cString[i];
			}

			delete[] cString;

			cString = new_cString;
		}
		currSymbol = std::cin.get();
	}
	cString[currLen] = '\0';

	return cString;
}

int MenuSelector(char symbol, Store * myStore)
{

	bool success = false;
	switch (symbol)
	{
		
	case 'A':
		myStore->AddNewProduct(*CreateNewProductFromConsole());
	    return 0;
	case 'X':
		std::cout << "Please enter the sku of the product you want to delete: " << std::endl;
		int skuX;
		std::cin >> skuX;
		std::cin.ignore();
		myStore->DeleteProduct(skuX);
		return 0;
	case 'C':
		std::cout << "Please enter the sku of the product you want to change: " << std::endl;
		int skuC;
		std::cin >> skuC;
		std::cin.ignore();
		std::cout << "Please enter P or C if you want to change the price or the count of a product " << std::endl;
		while (!success)
		{
			char command;
			std::cin >> command;
			std::cin.ignore();

			if (command == 'P')
			{
				success = true;
				std::cout << "Please enter the new price " << std::endl;
				double price;
				std::cin >> price;
				std::cin.ignore();
				myStore->ChangePriceOf(skuC, price);
				return 0;
				
			}
			else if (command == 'C')
			{
				success = true;
				std::cout << "Please enter the new count " << std::endl;
				int count;
				std::cin >> count;
				std::cin.ignore();
				myStore->ChangeCountOf(skuC, count);
				return 0;
			}
			std::cout << "Wrong Command!" << std::endl;
			std::cout << std::endl;
		}
		return 0;
	case 'D':
		std::cout << std::endl;
		myStore->PrintAll();
		return 0;
	case 'Q':
		return -1;

	default:
		system("cls");
		std::cout << "INVALID COMMAND!" << std::endl;
		std::cout << std::endl;
		return 0;
	}
}

void PrintMenu()
{
	system("cls");
	std::cout << "SELECT OPTION" << std::endl;
	std::cout << "A	Add new product" << std::endl;
	std::cout << "X	Delete product" << std::endl;
	std::cout << "C	Change product" << std::endl;
	std::cout << "D	Display products" << std::endl;
	std::cout << "Q	Quit" << std::endl;
	std::cout << std::endl;
}

Product * CreateNewProductFromConsole()
{
	std::cout << "Please Enter the Product Brand: " << std::endl;
	char * brand = CStringReader();
	std::cout << std::endl;

	std::cout << "Please Enter the Product Model: " << std::endl;
	char * model = CStringReader();
	std::cout << std::endl;

	std::cout << "Please Enter the Product Size: " << std::endl;
	char * size = CStringReader();
	std::cout << std::endl;

	std::cout << "Please Enter the Product Color: " << std::endl;
	char * color = CStringReader();
	std::cout << std::endl;

	std::cout << "Please Enter the Product Price: " << std::endl;
	double price;
	std::cin >> price;
	std::cin.ignore();
	std::cout << std::endl;

	std::cout << "Please Enter the Product Count: " << std::endl;
	double count;
	std::cin >> count;
	std::cin.ignore();
	std::cout << std::endl;


	return new Product(brand, model, size, color, price, count);
}
