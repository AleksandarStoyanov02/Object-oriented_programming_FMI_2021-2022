#pragma once
#include "MyString.h"
#include <ctime>

class Product
{
protected:
	enum Type {
		Fruit,
		Vegetable,
		Drink,
		AlcoholDrink,
		Unknown
	}type;
	MyString name;
	time_t dateOfArrival = time(NULL); //data na postupvane v sklada
	time_t expiryDate;   //srok na godnost
	MyString manufacturer;  //proizvoditel
	double price;

public:

	Product(const MyString& name, const MyString& manufacturer, const time_t expiryDate, double price);

	virtual Product* clone() const = 0;
	virtual void print() const = 0;

	const MyString& getName() const;
	const MyString& getManufacturer() const;

	time_t getDateOfArrival() const;
	time_t getExpiryDate() const;
	Type getType() const;

	void setName(const MyString& name);
	void setManufacturer(const MyString& manufacturer);

	double getPrice() const;
	void setPrice(double newPrice);

	virtual ~Product() = default;

};