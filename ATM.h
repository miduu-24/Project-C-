#pragma once
class ATM
{
private:
	float money[12] = {500, 200, 100, 50, 20, 10, 5, 1, 0.5, 0.1, 0.05, 0.01};
	int nrAppearance[12] = { 0 };

public:
	ATM();
	float findMoney(float);
	void addMoney(float);
	void addMore(float, int);
	void removeMoney(float);
	float getOneMoney(int);
	int getOneNr(int);
	int* getnrAppearance();
	float* getMoney();
	~ATM();
};