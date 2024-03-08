#include "Product.h"
#include <string.h>
#include <iostream>
using namespace std;

Product::Product()
{
    code = nullptr;
    name = nullptr;
    price = 0;
}

Product::Product(const char* codeNew,const char* nameNew, float priceNew)
{
    code = new char[strlen(codeNew) + 1];
    strcpy_s(code, strlen(codeNew) + 1, codeNew);

    name = new char[strlen(nameNew) + 1];
    strcpy_s(name, strlen(nameNew) + 1, nameNew);

    price = priceNew;
}

Product::Product(const Product& p)
{
    code = new char[strlen(p.code) + 1];
    strcpy_s(code, strlen(p.code) + 1, p.code);

    name = new char[strlen(p.name) + 1];
    strcpy_s(name, strlen(p.name) + 1, p.name);

    price = p.price;
}

char* Product::getCode()
{
    return code;
}

char* Product::getName()
{
    return name;
}

float Product::getPrice()
{
    return price;
}

void Product::setCode(const char* codeNew)
{
    code = new char[strlen(codeNew) + 1];
    strcpy_s(code, strlen(codeNew) + 1, codeNew);
}

void Product::setName(const char* nameNew)
{
    name = new char[strlen(nameNew) + 1];
    strcpy_s(name, strlen(nameNew) + 1, nameNew);
}

void Product::setPrice(float priceNew)
{
    price = priceNew;
}

Product& Product::operator=(const Product& p)
{
    if(this == &p)
		return *this;
    if (code != nullptr)
        delete[] code;
    if (name != nullptr)
        delete[] name;
    code = new char[strlen(p.code) + 1];
    strcpy_s(code, strlen(p.code) + 1, p.code);
    name = new char[strlen(p.name) + 1];
    strcpy_s(name, strlen(p.name) + 1, p.name);
    price = p.price;
    return *this;
}

bool Product::operator==(const Product& p)
{
    return strcmp(code, p.code) == 0 && strcmp(name, p.name) == 0 && price == p.price;
}

Product::~Product()
{
    if (code != nullptr)
        delete[] code;
    if (name != nullptr)
        delete[] name;
    price = 0;
}

ostream& operator<<(ostream& os, const Product& p)
{
    os << "Code: " << p.code << endl;
	os << "Name: " << p.name << endl;
	os << "Price: " << p.price << endl;
	return os;
}
