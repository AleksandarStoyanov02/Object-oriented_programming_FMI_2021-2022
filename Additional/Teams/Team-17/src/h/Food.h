#pragma once
#include "MyString.h"
#include "Product.h"

class Food : virtual 
	public Product
{
public:
	Food(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int ml, double price);

	void setKcal(int alcP);
	int getKcal() const;
private:

	int kcal;
};