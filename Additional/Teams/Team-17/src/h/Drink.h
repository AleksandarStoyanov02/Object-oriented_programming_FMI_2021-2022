#pragma once
#include "Product.h"

class Drink :virtual public Product
{
public:

	Drink() = default;
	Drink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, double price, int ml);

	int getMl() const;

	void setMl(int ml);

	Product* clone() const override;
	void print() const override;

protected:

	int ml;
};