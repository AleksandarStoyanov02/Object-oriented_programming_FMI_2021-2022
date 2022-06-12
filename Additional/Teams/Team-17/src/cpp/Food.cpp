#include "Food.h"
#include <iostream>
#include <ctime>

Food::Food(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int kcal, double price) :Product(name, manifacturer, expiryDate, price)
{
	setKcal(kcal);
}
void Food::setKcal(int kcal)
{
	this->kcal = kcal;
}
int Food::getKcal() const
{
	return kcal;
}