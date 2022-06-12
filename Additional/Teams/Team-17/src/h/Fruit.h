#pragma once
#include "Product.h"
#include "Food.h"

class Fruit :public Food
{
public:

	Fruit(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int kcal, double price);

	Product* clone() const override;

	void print() const override;

};
