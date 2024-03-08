#pragma once
#include <iostream>
using namespace std;
class Product
{
private:
	char* code;
	char* name;
	float price;

public:
	Product();
	Product(const char*,const char*, float);
	Product(const Product&);
	char* getCode();
	char* getName();
	float getPrice();
	void setCode(const char*);
	void setName(const char*);
	void setPrice(float);
	Product& operator=(const Product&);
	bool operator==(const Product&);
	~Product();
	friend ostream& operator<<(ostream&, const Product&);
};
