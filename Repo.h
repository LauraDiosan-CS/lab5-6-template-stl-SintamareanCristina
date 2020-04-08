#pragma once
#include "Car.h"
#include <list>
#include <iterator>
#include <string.h>
#include <algorithm>

using namespace std;

class Repo
{
private:
	list<Car> elem;

public:
	Repo();
	void addElem(Car);
	list<Car> getAll();
	void delElem(Car);
	void delAll();
	bool findElem(Car);
	Car getItemFromPos(int);
	void updateElem(Car, const char*, const char*, const char*);
	int dim();
	~Repo();
};
