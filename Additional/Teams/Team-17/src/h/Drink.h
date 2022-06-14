#pragma once
#include "Product.h"

class Drink : virtual public Product
{
public:
	Drink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, double price, int ml);

	int getMl() const;

	void setMl(int ml);

	Product* clone() const override;
	void print() const override;
	Type getType() const;

protected:

	int ml;
};