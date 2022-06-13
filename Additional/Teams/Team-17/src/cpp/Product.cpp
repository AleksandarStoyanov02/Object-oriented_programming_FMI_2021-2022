#include "Product.h"

Product::Product(const MyString& name, const MyString& manufacturer, const time_t expiryDate, double price)
{
	this->name = name;
	this->manufacturer = manufacturer;
	this->expiryDate = expiryDate;
	this->price = price;
	type = Unknown;
}

double Product::getPrice() const
{
	return price;
}
void Product::setPrice(double newPrice)
{
	if (price <= 0)
		throw "Invalid price!";
	this->price = price;
}
const MyString& Product::getName() const
{
	return name;
}
const MyString& Product::getManufacturer() const
{
	return manufacturer;
}
time_t Product::getDateOfArrival() const
{
	return dateOfArrival;
}
time_t Product::getExpiryDate() const
{
	return expiryDate;
}
Product::Type Product::getType() const
{
	return type;
}
void Product::setName(const MyString& name)
{
	this->name = name;
}
void Product::setManufacturer(const MyString& manufacturer)
{
	this->manufacturer = manufacturer;
}

