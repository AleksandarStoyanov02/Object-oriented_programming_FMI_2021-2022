#pragma once
#include "Product.h"
#include "Food.h"

class Vegetable :public Food
{
public:
	Vegetable(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int kcal, double price);

	Product* clone() const override;

	void print() const override;

	Type getType() const;
};