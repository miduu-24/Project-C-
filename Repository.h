#pragma once
#include "Product.h"
class Repository
{
private:
	Product elems[100];
	int nrApperace[100];
	int size;

public:
	Repository();
	Repository(const Repository&);
	void addElem(Product);
	int findElem(Product);
	int delElem(Product);
	int updateElem(Product, Product);
	Product* getAll();
	int* getAllNr();
	int getSize();
	Product getElem(int);
	Repository& operator=(const Repository&);
	bool operator==(const Repository&);
	~Repository();
};
