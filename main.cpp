#include "tests.h"
#include "Repository.h"
#include "Product.h"
#include "UI.h"
#include <iostream>

using namespace std;

int main()
{
	testsAll();
	cout << "Tests passed!" << endl;
	Repository repo;
	Service serv(repo);
	UI ui(serv);
	ui.run();
	return 0;
}