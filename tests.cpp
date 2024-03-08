#include "tests.h"
#include "Product.h"
#include "Repository.h"
#include "Service.h"
#include "ATM.h"
#include <assert.h>
#include <string.h>

void testsAll()
{
	testsProduct();
	testsRepository();
	testsService();
	testsATM();
}

void testsProduct()
{
	Product p1;
	assert(p1.getCode() == nullptr);
	assert(p1.getName() == nullptr);
	assert(p1.getPrice() == 0);

	Product p2("1", "2", 3);
	assert(strcmp(p2.getCode(), "1") == 0);
	assert(strcmp(p2.getName(), "2") == 0);
	assert(p2.getPrice() == 3);

	Product p3(p2);
	assert(p3 == p2);

	p1.setCode("1");
	p1.setName("2");
	p1.setPrice(3);
	assert(p1 == p2);

	p1 = p2;
	assert(p1 == p2);
}

void testsRepository()
{
	Repository repo;
	assert(repo.getSize() == 0);

	Product p1("1", "2", 3);
	repo.addElem(p1);
	assert(repo.getSize() == 1);
	assert(repo.getAll()[0] == p1);

	Product p2("4", "5", 6);
	repo.addElem(p2);
	assert(repo.getSize() == 2);
	assert(repo.getAll()[1] == p2);

	repo.delElem(p1);
	assert(repo.getSize() == 1);
	assert(repo.getAll()[0] == p2);

	Product p3("7", "8", 9);
	repo.addElem(p3);
	assert(repo.getSize() == 2);
	assert(repo.getAll()[1] == p3);

	Product p4("10", "11", 12);
	repo.updateElem(p3, p4);
	assert(repo.getSize() == 2);
	assert(repo.getAll()[1] == p4);
	assert(repo.findElem(p4) == 1);

	Repository repo2(repo);
	assert(repo2 == repo);
}

void testsService()
{
	Repository repo;
	Service serv(repo);
	assert(serv.getSize() == 0);

	Product p1("1", "2", 3);
	serv.addElem("1", "2", 3);
	assert(serv.getSize() == 1);
	assert(serv.getAll()[0] == p1);

	Product p2("4", "5", 6);
	serv.addElem("4", "5", 6);
	assert(serv.getSize() == 2);
	assert(serv.getAll()[1] == p2);

	serv.delElem("1", "2", 3);
	assert(serv.getSize() == 1);
	assert(serv.getAll()[0] == p2);

	Product p3("7", "8", 9);
	serv.addElem("7", "8", 9);
	assert(serv.getSize() == 2);
	assert(serv.getAll()[1] == p3);

	Product p4("10", "11", 12);
	serv.updateElem("7", "8", 9, "10", "11", 12);
	assert(serv.getSize() == 2);
	assert(serv.getAll()[1] == p4);
	assert(serv.findElem("10", "11", 12) == 1);

	serv.change(10, 10);
	assert(serv.getATM_nr()[5] == 0);

	serv.addSum(10);
	assert(serv.getATM_nr()[5] == 1);

	serv.deleteSum(10);
	assert(serv.getATM_nr()[5] == 0);
}

void testsATM()
{
	ATM atm;
	atm.addMoney(1);
	assert(atm.getOneNr(7) == 1);
	atm.addMoney(1);
	assert(atm.getOneNr(7) == 2);
	atm.addMoney(5);
	assert(atm.getOneNr(6) == 1);
	atm.addMore(5, 6);
	assert(atm.getOneNr(6) == 7);
	atm.removeMoney(1);
	assert(atm.getOneNr(7) == 1);
}