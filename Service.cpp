#include "Service.h"
#include "Product.h"

Service::Service()
{
}

Service::Service(const Repository& r)
{
	repo = r;
}

void Service::addElem(const char* code, const char* name, float price)
{
	Product p(code, name, price);
	repo.addElem(p);
}

int Service::findElem(const char* code, const char* name, float price)
{
	Product p(code, name, price);
	return repo.findElem(p);
}

int Service::delElem(const char* code, const char* name, float price)
{
	Product p(code, name, price);
	return repo.delElem(p);

}

int Service::updateElem(const char* codeOld, const char* nameOld, float priceOld, const char* codeNew, const char* nameNew, float priceNew)
{
	Product pOld(codeOld, nameOld, priceOld);
	Product pNew(codeNew, nameNew, priceNew);
	return repo.updateElem(pOld, pNew);
}

Product* Service::getAll()
{
	return repo.getAll();
}

int* Service::getAllNr()
{
	return repo.getAllNr();
}

int Service::getSize()
{
	return repo.getSize();
}

Product Service::getElem(int pos)
{
	return repo.getElem(pos);
}

int Service::findByCode(const char* code)
{
	for (size_t i = 0; i < repo.getSize(); i++)
	{
		if (strcmp(getElem(i).getCode(), code) == 0)
			return i;
	}
	return -1;
}


void Service::change(float change, float suma)
{
	addSum(suma);
	deleteSum(change);
}

void Service::addSum(float sum)
{
	for (int i = 0; i < 12; i++)
	{
		float money = atm.getOneMoney(i);
		while (sum >= money)
		{
			sum -= money;
			atm.addMoney(money);
		}
	}
}

void Service::deleteSum(float sum)
{
	if (atm.findMoney(sum) == -1)
	{
		int* nr = atm.getnrAppearance();
		for (int i = 0; i < 12; i++)
		{
			float money = atm.getOneMoney(i);
			while (sum >= money && nr[i] > 0)
			{
				sum -= money;
				cout << sum << endl;
				atm.removeMoney(money);
			}
		}
		if(sum)
			throw exception("Not enough money in ATM for the change");
	}
	else
	{
		atm.removeMoney(sum);
	}
}

void Service::atmMoca(float sum, int nr)
{
	atm.addMore(sum, nr);
}

int* Service::getATM_nr()
{
	return atm.getnrAppearance();
}

float* Service::getATM_val()
{
	return atm.getMoney();
}

Service::~Service()
{
}

