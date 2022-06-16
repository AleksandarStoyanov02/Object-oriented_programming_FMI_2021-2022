#pragma warning (disable:4996)
#include "Drink.h"
#include <iostream>

Drink::Drink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, double price, int ml) :Product(name, manifacturer, expiryDate, price)
{
	type = Type::Drink;
	setMl(ml);
}
int Drink::getMl() const
{
	return ml;
}

void Drink::setMl(int ml)
{
	if(ml > 0 && ml < 10000)
		this->ml = ml;
}


Product* Drink::clone() const
{
	return new Drink(*this);
}
void Drink::print() const
{
	tm* now = localtime(&dateOfArrival);
	std::cout << "Name: " << name << ", Manufacturer: " << manufacturer << ", Date of arrival: " << (now->tm_year + 1900) << "." << (now->tm_mon + 1) << "." << now->tm_mday << ", expiryDate: " << expiryDate << ", ml " << ml << std::endl;
}

Product::Type Drink::getType() const
{
	return type;
}
