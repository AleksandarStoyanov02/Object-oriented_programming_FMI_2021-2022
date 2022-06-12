#pragma warning (disable:4996)
#include "AlcoholDrink.h"
#include <iostream>
AlcoholDrink::AlcoholDrink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int ml, double price, int alcP) : Drink(name, manifacturer, expiryDate, ml, price), Product(name, manifacturer, expiryDate, price)
{
	setAlcP(alcP);
}
void AlcoholDrink::setAlcP(int alcP)
{
	if (alcP < 5 || alcP > 98)
		alcP = 50;
	this->alcP = alcP;
}
int AlcoholDrink::getAlcP() const
{
	return alcP;
}

void AlcoholDrink::print() const
{
	tm* now = localtime(&dateOfArrival);
	std::cout << "Name: " << name << ", Manufacturer: " << manufacturer << ", Date of arrival: " << (now->tm_year + 1900) << "." << (now->tm_mon + 1) << "." << now->tm_mday << ", expiryDate: " << expiryDate << ", ml " << ml << ", alcohol: " << alcP << "%" << std::endl;
}
Product* AlcoholDrink::clone() const
{
	return new AlcoholDrink(*this);
}