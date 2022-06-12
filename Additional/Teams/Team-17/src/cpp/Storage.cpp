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

void Storage::addProduct(Product* product)
{
	if (productsCount == capacity)
		resize();
	products[productsCount++] = product;
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
	for (int i = index; i < productsCount; i++)
		products[i] = products[i + 1];
	productsCount--;
	logData.pushBack("Removed item");
}
void Storage::remove(const MyString& name, const MyString& manufacturer, const time_t expiryDate, double price)
{
	int index = -1;
	for (int i = 0; i < productsCount; i++)
	{
		if (products[i]->getName() == name && products[i]->getManufacturer() == manufacturer && products[i]->getExpiryDate() == expiryDate && products[i]->getPrice() == price)
		{
			index = i;
			break;
		}
	}
	if (index < 0)
		throw "No such item in the storage!";
	remove(index);
}
void Storage::remove(Product* product)
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
void Storage::log()
{
	for (int i = 0; i < logData.getSize(); i++)
	{
		std::cout << i + 1 << ". " << logData[i].c_str() << std::endl;
	}
}
void Storage::clean()
{
	time_t currDate = std::time(NULL);
	std::tm* now = std::localtime(&currDate);
	for (int i = 0; i < productsCount; i++)
	{
		if (products[i]->getExpiryDate() >= currDate)
			remove(i);
	}
}
double Storage::getTotalLostOfMoney() const
{
	return lostMoney;
}


char* readStringFromFile(std::ifstream& file) {
	size_t stringLength;
	file.read((char *)&stringLength, sizeof(size_t));
	char* str = new char[stringLength + 1];
	file.read(str, stringLength);
	str[stringLength] = '\0';

	return str;
}

bool Storage::read(const MyString& name)
{
	std::ifstream file(name.c_str(), std::ios::_Nocreate);
	if (!file.is_open())
		return false;
	size_t size;
	file.read((char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++) {
		MyString productName = readStringFromFile(file);
		time_t dateOfArrival;
		size_t sizeOfDateOfArrival;
		file.read((char*)&sizeOfDateOfArrival, sizeof(size_t));
		file.read((char*)&dateOfArrival, sizeOfDateOfArrival);

		time_t expiryDate;
		size_t sizeOfExpiryDate;
		file.read((char*)&sizeOfExpiryDate, sizeof(size_t));
		file.read((char*)&expiryDate, sizeOfExpiryDate);

		MyString manufacturerName = readStringFromFile(file);

		double price;
		file.read((char*)&price, sizeof(double));
	}


	file.close();
	return true;
}

bool Storage::write(const MyString& name) const
{
	std::ofstream file(name.c_str());
	if (!file.is_open())
		return false;

	size_t size = getCount();
	file.write((const char*)&size, sizeof(size_t));
	for (size_t i = 0; i < size; i++) {
		size_t sizeOfName = strlen(products[i]->getName().c_str());
		size_t sizeOfManufacturer = strlen(products[i]->getManufacturer().c_str());
		double price = products[i]->getPrice();
		time_t expiryDate = products[i]->getExpiryDate();
		time_t dateOfArrival = products[i]->getDateOfArrival();

		size_t sizeOfDateOfArrival = sizeof(dateOfArrival);
		size_t sizeOfExpiryDate = sizeof(expiryDate);
		file.write((const char*)&sizeOfName, sizeof(size_t));
		file.write(products[i]->getName().c_str(), sizeOfName);

		file.write((const char*)&sizeOfDateOfArrival, sizeof(size_t));
		file.write((const char*)&dateOfArrival, sizeOfDateOfArrival);

		file.write((const char*)&sizeOfExpiryDate, sizeof(size_t));
		file.write((const char*)&expiryDate, sizeOfExpiryDate);

		file.write((const char*)&sizeOfManufacturer, sizeof(size_t));
		file.write(products[i]->getManufacturer().c_str(), sizeOfManufacturer);

		file.write((const char*)&price, sizeof(double));
	}
	file.close();
	return true;
}

void Storage::print() const
{
	size_t size = getCount();
	for (size_t i = 0; i < size; i++) {
		std::cout << i + 1 << ". ";
		products[i]->print();
	} 
}
