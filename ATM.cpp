#include "ATM.h"

ATM::ATM()
{
}

float ATM::findMoney(float sum)
{
	for (int i = 0; i < 12; i++)
	{
		if (money[i] == sum)
			return i;
	}
	return -1;
}

void ATM::addMoney(float sum)
{
	int pos = findMoney(sum);
	nrAppearance[pos]++;
}

void ATM::addMore(float sum, int nr)
{
	int pos = findMoney(sum);
	nrAppearance[pos] += nr;
}

void ATM::removeMoney(float sum)
{
	int pos = findMoney(sum);
	nrAppearance[pos]--;
}

float ATM::getOneMoney(int pos)
{
	return money[pos];
}

int ATM::getOneNr(int pos)
{
	return nrAppearance[pos];
}

int* ATM::getnrAppearance()
{
	return nrAppearance;
}

float* ATM::getMoney()
{
	return money;
}

ATM::~ATM()
{
}
