#pragma once
#include "Car.h"
#include "Repo.h"
#include <list>
#include <iterator>
#include <algorithm>

class Service {
private:
	Repo r;
	int parking;
public:
	int n;
	Service();
	Service(const Repo&);
	~Service();
	int addElem(Car c);
	list<Car> getAll();
	int delElem(Car);
	int updateElem(Car, const char*, const char*, const char*);
	Car getItemFromPos(int);
	bool findElem(Car);
	int dim();
	void setParking(int);
	int intrareParcare(Car);
	int iesireParcare(Car);
};
