#include "Storage.h"
#include <iostream>
#pragma warning (disable:4996)

void Storage::free()
{
	for (size_t i = 0; i < productsCount; i++)
		delete products[i];
	delete[] products;
}
void Storage::copyFrom(const Storage& other)
{
	products = new Product * [other.productsCount];
	productsCount = other.productsCount;
	capacity = other.capacity;

	for (size_t i = 0; i < productsCount; i++)
	{
		products[i] = other.products[i]->clone();
	}
	logData = other.logData;
	lostMoney = other.lostMoney;
}

void Storage::resize()
{
	Product** newCollection = new Product * [capacity *= 2];
	for (size_t i = 0; i < productsCount; i++)
		newCollection[i] = products[i];
	delete[] products;
	products = newCollection;
}

Storage::Storage() :logData()
{
	capacity = 8;
	productsCount = 0;
	products = new Product * [capacity];
	lostMoney = 0;
}

Storage::Storage(const Storage& other)
{
	copyFrom(other);
}
Storage& Storage::operator=(const Storage& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Storage::~Storage()
{
	free();
}

size_t Storage::getCount() const
{
	return productsCount;
}

void Storage::addProduct(const Product* product)
{
	if (productsCount == capacity)
		resize();
	products[productsCount++] = product->clone();
}

void Storage::addFruit(const MyString& name, const MyString& manufacturer, const time_t expiryDate, int kcal, double price)
{
	Food* fruit = new Fruit(name, manufacturer, expiryDate, kcal, price);
	addProduct(fruit);
	logData.pushBack("Add fruit");
}
void Storage::addDrink(const MyString& name, const MyString& manufacturer, const time_t expiryDate, int ml, double price)
{
	Drink* drink = new Drink(name, manufacturer, expiryDate, price, ml);
	addProduct(drink);
	logData.pushBack("Add Drink");
}

void Storage::addVegetable(const MyString& name, const MyString& manufacturer, const time_t expiryDate, int kcal, double price)
{
	Vegetable* vegetable = new Vegetable(name, manufacturer, expiryDate, kcal, price);
	addProduct(vegetable);
	logData.pushBack("Add Vegetable");
}
void Storage::addAlcoholDrink(const MyString& name, const MyString& manufacturer, const time_t expiryDate, int ml, int alcP, double price)
{
	AlcoholDrink* drink = new AlcoholDrink(name, manufacturer, expiryDate, ml, price, alcP);
	addProduct(drink);
	logData.pushBack("Add Alcohol Drink");
}

void Storage::remove(size_t index)
{
	if (index >= productsCount)
		throw "Invalid index!";
	delete products[index];
	for (int i = index; i < productsCount - 1; i++)
		products[i] = products[i + 1];
	productsCount--;
	logData.pushBack("Removed item");
}
void Storage::remove(const MyString& name, const MyString& manufacturer)
{
	int index = -1;
	for (int i = 0; i < productsCount; i++)
	{
		if (products[i]->getName() == name && products[i]->getManufacturer() == manufacturer)
		{
			index = i;
			break;
		}
	}
	if (index < 0)
		throw "No such item in the storage!";
	remove(index);
}
void Storage::remove(const Product* product)
{
	int index = -1;
	for (int i = 0; i < productsCount; i++)
	{
		if (products[i] == product)
		{
			index = i;
			break;
		}
	}
	if (index < 0)
		throw "No such item in the storage!";
	remove(index);
}

double Storage::getCurrentIncome() const
{
	double income = 0;
	for (int i = 0; i < productsCount; i++)
		income += products[i]->getPrice();
	return income;
}
void Storage::log() const
{
	for (int i = 0; i < logData.getSize(); i++)
	{
		std::cout << i + 1 << ". " << logData[i].c_str() << std::endl;
	}
}
bool Storage::clean()
{
	time_t currDate = std::time(NULL);
	std::tm* now = std::localtime(&currDate);
	for (int i = 0; i < productsCount; i++)
	{
		if (products[i]->getExpiryDate() >= currDate) {
			lostMoney += products[i]->getPrice();
			remove(i);
		}
	}
	getTotalLostOfMoney();
	return true;
}
double Storage::getTotalLostOfMoney() const
{
	return lostMoney;
}



void Storage::print() const
{
	size_t size = getCount();
	for (size_t i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
		products[i]->print();
	} 
}
