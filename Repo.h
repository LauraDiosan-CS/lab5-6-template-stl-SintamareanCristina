#pragma once
#include "Car.h"
#include <list>
#include <iterator>
#include <string.h>
#include <algorithm>

using namespace std;

class Repo
{
protected:
	list<Car> elem;

public:
	Repo();
	int addElem(Car);
	list<Car> getAll();
	int delElem(Car);
	bool findElem(Car);
	Car getItemFromPos(int);
	void updateElem(Car, const char*, const char*, const char*);
	int dim();
	~Repo();
};

