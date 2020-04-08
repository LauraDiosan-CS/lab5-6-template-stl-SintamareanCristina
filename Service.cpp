#include "Service.h"
#include "Car.h"
#include <iostream>
using namespace std;

//constructor fara param
Service::Service() {
	this->r;
}

//destructor
Service::~Service() {
}

//adauga un element de tip Car
void Service::addElem(Car& c) {
	r.addElem(c);
}

/*void Service::addElem(Car& c, int& x) {
	if (strcmp(c.getStatus(), "ocupat") == 0) cout << "Eroare" << endl;
	else
		if (x >= 1) {
			c.setStatus("ocupat");
			r.addElem(c);
			x--;
		}

}*/

//returneaza toate elementele de tip Car
list<Car> Service::getAll() {
	return r.getAll();
}

//sterge un element de tip Car
void Service::delElem(Car c) {
	r.delElem(c);
}

//modifica un element de tip Car
void Service::updateElem(Car c, const char* numePosesor, const char* nrInmatriculare, const char* status) {
	r.updateElem(c, numePosesor, nrInmatriculare, status);
}

//returneaza elementul de tip Car de pe o anumita pozitie
Car Service::getItemFromPos(int i) {
	return r.getItemFromPos(i);
}

bool Service::findElem(Car c) {
	return r.findElem(c);
}

int Service::dim() {
	return r.dim();
}