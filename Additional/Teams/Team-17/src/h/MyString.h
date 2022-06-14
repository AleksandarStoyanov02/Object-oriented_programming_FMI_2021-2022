#pragma once
#include <fstream>
#include "Vector.hpp"

class MyString
{
private:

	char* str;
	size_t size;

	void copyFrom(const MyString&);
	void free();

public:

	MyString();
	MyString(const char*);

	MyString(const MyString&);
	MyString& operator=(const MyString&);
	MyString& operator=(MyString&& other);

	~MyString();

	size_t getSize() const;
	void concat(const MyString&);

	const char* c_str() const;

	MyString& operator+=(const MyString&);
	Vector<MyString> split(char s) const;
	friend std::istream& operator>>(std::istream&, MyString&);
	friend std::ostream& operator<<(std::ostream&, const MyString&);

	void getLine(std::istream& outFile);
	double parseDouble() const;
	int parseInt() const;
};

MyString operator+(const MyString&, const MyString&);

bool operator==(const MyString&, const MyString&);
bool operator<=(const MyString&, const MyString&);
bool operator<(const MyString&, const MyString&);