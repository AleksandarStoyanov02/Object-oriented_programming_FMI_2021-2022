#pragma once
#include "Drink.h"

class AlcoholDrink : public Drink
{
private:

	int alcP;

public:

	AlcoholDrink() = default;
	AlcoholDrink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int ml, double price, int alcP = 5);

	void setAlcP(int alcP);
	int getAlcP() const;

	Product* clone() const override;
	void print() const override;
};