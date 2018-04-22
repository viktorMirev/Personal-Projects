#include<iostream>

#include"Store.h"

Store::Store()
{
	this->currentMax = 128;
	this->allProducts = new Product*[currentMax];
	this->currentCount = 0;
}

Store::~Store()
{
	this->Delete();
}

void Store::PrintAll() const
{
	if (this->currentCount != 0)
	{
		for (size_t i = 0; i < this->currentCount; i++)
		{
			this->allProducts[i]->Print();
			std::cout << std::endl;
		}
		return;
	}

	std::cout << "No Products registered!" << std::endl;

	
}

void Store::AddNewProduct(const Product& other)
{
	if (this->currentCount == this->currentMax)
	{
		this->currentMax *= 2;
		Product ** new_AllProducts = new Product*[this->currentMax];

		for (size_t i = 0; i < currentCount; i++)
		{
			new_AllProducts[i] = allProducts[i];
		}
		delete[] allProducts;

		allProducts = new_AllProducts;
	}

	Product * new_product = new Product(other);


	this->allProducts[this->currentCount] = new_product;
	this->currentCount++;

}

void Store::DeleteProduct(int sku)
{
	bool found = false;
	for (size_t i = 0; i < this->currentCount; i++)
	{
		if (allProducts[i]->GetSku() == sku)
		{
			delete allProducts[i];

			//shift all of the products
			for (size_t j = i; j < currentCount - 1; j++)
			{
				allProducts[j] = allProducts[j + 1];
			}
			found = true;
			this->currentCount--;
			break;
		}
	}
	if (!found)
	{
		std::cout << "No such SKU found!" << std::endl;
	}
}

void Store::ChangePriceOf(int sku, double price)
{
	int index = this->FindSku(sku);
	if (index == -1)
	{
		return;
	}
	allProducts[index]->SetPrice(price);

}

void Store::ChangeCountOf(int sku, int count)
{
	int index = this->FindSku(sku);
	if (index == -1)
	{
		return;
	}
	allProducts[index]->SetCount(count);
}

void Store::Delete()
{
	for (size_t i = 0; i < this->currentCount; i++)
	{
		delete this->allProducts[i];
	}
	delete[] allProducts;
}

int Store::FindSku(int sku)
{
	int index = -1;
	for (size_t i = 0; i < this->currentCount; i++)
	{
		if (allProducts[i]->GetSku() == sku)
		{
			index = i;
			break;
		}
	}
	if (index == -1)
	{
		std::cout << "No such SKU found!" << std::endl;
	}
	return index;
}
