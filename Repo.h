#pragma once
#include "Car.h"
#include <list>

using namespace std;

class Repo
{
private:
	list<Car> elem;

public:
	Repo();
	void addElem(Car);
	list<Car> getAll();
	int dim();
	~Repo();
};