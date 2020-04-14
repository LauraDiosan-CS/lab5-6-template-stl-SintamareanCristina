#include "Repo.h"


Repo::Repo()
{
}

int Repo::addElem(Car c) {
	list<Car>::iterator it;
	int ok = 1;
	for (it = elem.begin(); it != elem.end(); it++)
		if (strcmp((*it).getNrInmatriculare(), c.getNrInmatriculare()) == 0)
			ok = 0;
	it = find(elem.begin(), elem.end(), c);
	if (it == elem.end() and ok == 1)
	{
		elem.push_back(c);
		return 0;
	}
	return -1;
}

list<Car> Repo::getAll() {
	return elem;
}

int Repo::delElem(Car c) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end())
	{
		elem.erase(it);
		return 0;
	}
	else
		return -1;
}

bool Repo::findElem(Car c) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) return true;
	return false;

}

Car Repo::getItemFromPos(int i) {
	list<Car>::iterator it = elem.begin();
	std::advance(it, i);
	return *it;
}

void Repo::updateElem(Car c, const char* numePosesor, const char* nrInmatriculare, const char* status) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) {
		(*it).setNumePosesor(numePosesor); //it->setNumePosesor(numePosesor)
		(*it).setNrInmatriculare(nrInmatriculare);
		(*it).setStatus(status);
	}
}

Repo::~Repo()
{}

int Repo::dim() {
	return elem.size();
}