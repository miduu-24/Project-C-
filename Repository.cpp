#include "Repository.h"

Repository::Repository()
{
	size = 0;
}

Repository::Repository(const Repository& repo)
{
	size = repo.size;
	for (int i = 0; i < size; i++)
	{
		elems[i] = repo.elems[i];
		nrApperace[i] = repo.nrApperace[i];
	}
}

void Repository::addElem(Product p)
{
	int pos = findElem(p);
	if (pos != -1)
	{
		nrApperace[pos]++;
	}
	else
	{
		elems[size] = p;
		nrApperace[size] = 1;
		size++;
	}
}

int Repository::delElem(Product p)
{
	int pos = findElem(p);
	if (pos != -1)
	{
		if (nrApperace[pos] == 1)
		{
			for (int i = pos; i < size - 1; i++)
			{
				elems[i] = elems[i + 1];
				nrApperace[i] = nrApperace[i + 1];
			}
			size--;
			return 1;
		}
		else
		{
			nrApperace[pos]--;
			return 1;
		}
	}
	return 0;
}

int Repository::updateElem(Product pOld, Product pNew)
{
	int pos = findElem(pOld);
	if (pos != -1)
	{
		elems[pos] = pNew;
		return 1;
	}
	return 0;
}

int Repository::findElem(Product p)
{
	for (int i = 0; i < size; i++)
	{
		if (elems[i] == p)
		{
			return i;
		}
	}
	return -1;
}

Product* Repository::getAll()
{
	return elems;
}

int* Repository::getAllNr()
{
	return nrApperace;
}

int Repository::getSize()
{
	return size;
}

Product Repository::getElem(int i)
{
	return elems[i];
}

Repository& Repository::operator=(const Repository& repo)
{
	size = repo.size;
	for (int i = 0; i < size; i++)
	{
		elems[i] = repo.elems[i];
	}
	return *this;
}

bool Repository::operator==(const Repository& repo)
{
	if (size != repo.size)
	{
		return false;
	}
	for (int i = 0; i < size; i++)
	{
		if (!(elems[i] == repo.elems[i]))
		{
			return false;
		}
	}
	return true;
}

Repository::~Repository()
{
}
