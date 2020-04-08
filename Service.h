#pragma once
#include "Car.h"
#include "Repo.h"
#include <list>
#include <iterator>
#include <algorithm>

class Service {
private:
	Repo r;
public:
	Service();
	~Service();
	void addElem(Car& c);
	list<Car> getAll();
	void delElem(Car);
	void updateElem(Car, const char*, const char*, const char*);
	Car getItemFromPos(int);
	bool findElem(Car);
	int dim();
};