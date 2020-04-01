#include "Repo.h"


Repo::Repo()
{
}

void Repo::addElem(Car c) {
	elem.push_back(c);
}

list<Car> Repo::getAll() {
	return elem;
}

Repo::~Repo()
{}

int Repo::dim() {
	return elem.size();
}