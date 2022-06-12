#pragma once
#include "Product.h"
#include "Drink.h"
#include "AlcoholDrink.h"
#include "Fruit.h"
#include "Vegetable.h"
#include "Vector.h"

class Storage
{
private:
	Vector<MyString> logData;
	Product** products;
	size_t productsCount;
	size_t capacity;

	void free();
	void copyFrom(const Storage& other);
	void resize();

	void addProduct(Product* account);

	double lostMoney;
public:

	Storage();
	Storage(const Storage& other);
	Storage& operator=(const Storage& other);
	~Storage();

	size_t getCount() const;

	void addFruit(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int kcal, double price);
	void addVegetable(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int kcal, double price);
	void addDrink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int ml, double price);
	void addAlcoholDrink(const MyString& name, const MyString& manifacturer, const time_t expiryDate, int ml, int alcP, double price);

	void remove(size_t index); // remove product by index
	void remove(const MyString& name, const MyString& manifacturer, const time_t expiryDate, double price); //remove first product with these specifics
	void remove(Product* product);//remove product

	void log();//get information 

	double getCurrentIncome() const;//return the price of all products

	void clean();//delete all products with expired date

	double getTotalLostOfMoney() const;// get lost money due to expired date


};