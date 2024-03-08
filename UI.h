#pragma once
#include "Service.h"

class UI
{
private:
	Service serv;

public:
	UI();
	UI(const Service& s);
	void printMenu();
	void readElems(char*, char*, float&);
	void addElemUI();
	void findElemUI();
	void delElemUI();
	void updateElemUI();
	void printAll();
	void printElem(int pos);
	void printSize();
	void buyProduct();
	void mocaValue();
	void atmMoca();
	void moneyATM();
	void run();
	~UI();
};
