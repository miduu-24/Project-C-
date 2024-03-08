#include "UI.h"
#include <iostream>
using namespace std;

UI::UI()
{
}

UI::UI(const Service& s)
{
	serv = s;
}

void UI::printMenu()
{
	cout << endl;
	cout << "Menu:" << endl;
	cout << "1. Add product." << endl;
	cout << "2. Find product." << endl;
	cout << "3. Delete product." << endl;
	cout << "4. Update product." << endl;
	cout << "5. Print all products." << endl;
	cout << "6. Print size." << endl;
	cout << "-1. Moca value." << endl;
	cout << "***" << endl;
	cout << "ATM:" << endl;
	cout << "7. Buy product." << endl;
	cout << "8. Moca value." << endl;
	cout << "9. Money in ATM." << endl;
	cout << "***" << endl;
	cout << "0. Exit." << endl;
	cout << "Your option: ";
}

void UI::readElems(char* code, char* name, float& price)
{
	cout << "Code: ";
	cin.get();
	cin.getline(code, 20);
	cout << "Name: ";
	cin.getline(name, 20);
	cout << "Price: ";
	cin >> price;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore();
		throw exception("Invalid price! The price must be a float!");
	}
	else
	{
		if (price < 0)
			throw exception("Invalid price! The price must be a positive integer!");
	}
}

void UI::addElemUI()
{
	char code[20], name[20];
	float price;
	try
	{
		readElems(code, name, price);
		serv.addElem(code, name, price);
		cout << "Product added successfully!" << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::findElemUI()
{
	char code[20], name[20];
	float price;
	try
	{
		readElems(code, name, price);
		int pos = serv.findElem(code, name, price);
		if (pos == -1)
			cout << "Product not found!" << endl;
		else
			cout << "Product found successfully!" << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::delElemUI()
{
	char code[20], name[20];
	float price;
	try
	{
		readElems(code, name, price);
		if(serv.delElem(code, name, price))
			cout << "Product deleted successfully!" << endl;
		else
			cout << "Product not found!" << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::updateElemUI()
{
	char codeOld[20], nameOld[20], codeNew[20], nameNew[20];
	float priceOld, priceNew;
	try
	{
		cout << "Old product:" << endl;
		readElems(codeOld, nameOld, priceOld);
		cout << "New product:" << endl;
		readElems(codeNew, nameNew, priceNew);
		if(serv.updateElem(codeOld, nameOld, priceOld, codeNew, nameNew, priceNew))
			cout << "Product updated successfully!" << endl;
		else
			cout << "Product not found!" << endl;
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}

void UI::printAll()
{
	if (serv.getSize() == 0)
	{
		cout << "There are no products!" << endl;
		return;
	}

	Product* products = serv.getAll();
	int* nr = serv.getAllNr();
	for (int i = 0; i < serv.getSize(); i++)
	{
		cout << nr[i] << " ";
		cout << products[i];
		cout << endl;
	}
}

void UI::printElem(int pos)
{
	int* nr = serv.getAllNr();
	cout << nr[pos] << " " << serv.getElem(pos);
}

void UI::printSize()
{
	cout << "Size: " << serv.getSize() << endl;
}

void UI::buyProduct()
{
	char code[20];
	cout << "Code: ";
	cin.get();
	cin.getline(code, 20);
	int pos = serv.findByCode(code);
	if (pos != -1)
	{
		Product p = serv.getElem(pos);
		cout << "Product price: " << p.getPrice() << endl;
		cout << "Add sum: ";
		float sum;
		cin >> sum;
		while (sum < p.getPrice())
		{
			cout << "You need to add more if you want to buy this product." << endl;
			cout << "Add more: ";
			float sum1;
			cin >> sum1;
			sum += sum1;
		}
		if (sum > p.getPrice())
		{
			serv.change(sum - p.getPrice(), sum);
			serv.delElem(p.getCode(), p.getName(), p.getPrice());
			cout << "This is your change: " << sum - p.getPrice();
		}
		else
		{
			serv.addSum(sum);
			serv.delElem(p.getCode(), p.getName(), p.getPrice());
			cout << "Thank you for buying!" << endl;
		}
	}
	else
	{
		cout << "Product not found!" << endl;
	}
}

void UI::mocaValue()
{
	serv.addElem("1", "apa", 3);
	serv.addElem("5", "snickers", 4);
	serv.addElem("1", "apa", 3);
	serv.addElem("1", "apa", 3);
	serv.addElem("5", "snickers", 4);
	serv.addElem("5", "snickers", 4);
	serv.addElem("1", "apa", 3);
	serv.addElem("6", "acadea", 1);
	serv.addElem("6", "acadea", 1);
	serv.addElem("6", "acadea", 1);
	cout << "Done!" << endl;
}

void UI::atmMoca()
{
	serv.atmMoca(500, 10);
	serv.atmMoca(200, 10);
	serv.atmMoca(100, 10);
	serv.atmMoca(50, 10);
	serv.atmMoca(20, 10);
	serv.atmMoca(10, 10);
	serv.atmMoca(5, 10);
	serv.atmMoca(1, 10);
	serv.atmMoca(0.5, 10);
	serv.atmMoca(0.1, 10);
	serv.atmMoca(0.05, 10);
	serv.atmMoca(0.01, 10);
	cout << "Done!" << endl;
}

void UI::moneyATM()
{
	float* money = serv.getATM_val();
	int* nr = serv.getATM_nr();
	for (int i = 0; i < 12; i++)
	{
		cout << nr[i] << " money: " << money[i] << endl;
	}
}

void UI::run()
{
	bool ok = true;
	while (ok)
	{
		printMenu();
		int option;
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
		{
			addElemUI();
			break;
		}
		case 2:
		{
			findElemUI();
			break;
		}
		case 3:
		{
			delElemUI();
			break;
		}
		case 4:
		{
			updateElemUI();
			break;
		}
		case 5:
		{
			printAll();
			break;
		}
		case 6:
		{
			printSize();
			break;
		}
		case 7:
		{
			try
			{ 
			buyProduct();
			}
			catch (exception& ex)
			{
				cout << ex.what() << endl;
			}
			break;
		}
		case 8:
		{
			atmMoca();
			break;
		}
		case 9:
		{
			moneyATM();
			break;
		}
		case 0:
		{
			ok = false;
			cout << "Bye!" << endl;
			break;
		}
		case -1:
		{
			mocaValue();
			break;
		}
		default:
		{
			cout << "Invalid option!" << endl;
			break;
		}
		}
	}
}

UI::~UI()
{
}
