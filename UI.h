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
	UI(const Service&);
	void printMenu();
	void addElem();
	void getAll();
	void delElem();
	void updateElem();
	void intrareParcare();
	void iesireParcare();
	void run();
};