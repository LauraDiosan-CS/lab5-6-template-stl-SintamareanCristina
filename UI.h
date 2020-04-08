#pragma once
#include "Car.h"
#include "Repo.h"
#include "Service.h"
#include <list>
#include <iterator>
#include <algorithm>

class UI {
private:
	Service s;
public:
	UI();
	~UI();
	void printMenu();
	void addElem(Service& s);
	void getAll(Service& s);
	void delElem(Service& s);
	void updateElem(Service& s);
};
