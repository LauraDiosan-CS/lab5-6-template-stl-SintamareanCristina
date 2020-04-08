// lab 6-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "Service.h"
#include "UI.h"
#include "Tests.h"
using namespace std;

int main() {
	bool k = true;
	Service s; UI ui;
	tests();
	ui.printMenu();
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			ui.addElem(s);
			ui.printMenu();
			continue;
		}
		if (option == 2)
		{
			ui.getAll(s);
			ui.printMenu();
			continue;
		}
		if (option == 3)
		{
			ui.updateElem(s);
			ui.printMenu();
			continue;
		}
		if (option == 4)
		{
			ui.delElem(s);
			ui.printMenu();
			continue;
		}
		if (option == 5)
			k = false;
	}
	return 0;
}