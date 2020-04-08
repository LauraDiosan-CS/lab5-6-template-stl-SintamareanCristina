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

void Repo::delElem(Car c) {
	list<Car>::iterator it;
	it = find(elem.begin(), elem.end(), c);
	if (it != elem.end()) elem.erase(it);
}

void Repo::delAll() {
	list<Car>::iterator it;
	it = elem.begin();
	while (it != elem.end()) elem.erase(it);
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