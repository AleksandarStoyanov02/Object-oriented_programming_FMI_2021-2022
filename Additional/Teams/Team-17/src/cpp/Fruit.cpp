#include "Fruit.h"
#include <iostream>
#pragma warning (disable:4996)

Fruit::Fruit(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int kcal, double price) :Food(name, manifacturer, expiryDate, kcal, price), Product(name, manifacturer, expiryDate, price)
{}
Product* Fruit::clone() const
{
	return new Fruit(*this);
}

void Fruit::print() const
{
	tm* now = localtime(&dateOfArrival);
	std::cout << "Fruit, Name: " << name << ", Manufacturer: " << manufacturer << ", Date of arrival: " << (now->tm_year + 1900) << "." << (now->tm_mon + 1) << "." << now->tm_mday << ", expiryDate: " << expiryDate << ", kcal " << getKcal() << std::endl;
}