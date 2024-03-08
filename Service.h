#pragma once
#include "Repository.h"
#include "Product.h"
#include "ATM.h"

class Service
{
private:
	Repository repo;
	ATM atm;
public:
	Service();
	Service(const Repository& repo);
	void addElem(const char* code, const char* name, float price);
	int findElem(const char* code, const char* name, float price);
	int delElem(const char* code, const char* name, float price);
	int updateElem(const char* codeOld, const char* nameOld, float priceOld, const char* codeNew, const char* nameNew, float priceNew);
	Product* getAll();
	int* getAllNr();
	int getSize();
	Product getElem(int pos);
	int findByCode(const char* code);
	//atm
	void change(float change, float sum);
	void addSum(float sum);
	void deleteSum(float sum);
	void atmMoca(float sum, int nr);
	int* getATM_nr();
	float* getATM_val();
	~Service();
};
