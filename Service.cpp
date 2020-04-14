#include "Service.h"
#include "Car.h"
#include <iostream>
using namespace std;

//constructor fara param
Service::Service(const Repo& repository) {
	this->r = repository;
}

Service::Service() {
	n = 5;
}

//destructor
Service::~Service() {
}

//adauga un element de tip Car

int Service::addElem(Car c) {
	if (strcmp(c.getStatus(), "ocupat") == 0) {
		int k = 0;
		for (int i = 0; i < r.dim(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking) {
			n++;
			return -1;
		}
	}
	int rez = this->r.addElem(c);
	return rez;
}

//returneaza toate elementele de tip Car
list<Car> Service::getAll() {
	return r.getAll();
}

//sterge un element de tip Car
int Service::delElem(Car c) {
	if (strcmp(c.getStatus(), "liber") == 0) {
		return this->r.delElem(c);
	}
	else
		return -2;
}

//modifica un element de tip Car
int Service::updateElem(Car c, const char* numePosesor, const char* nrInmatriculare, const char* status) {
	if (strcmp(status, "ocupat") == 0) {
		int k = 0;
		for (int i = 0; i < r.dim(); i++)
			if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
				k++;
		if (k >= parking) {
			n++;
			return -1;
		}
	}
	this->r.updateElem(c, numePosesor, nrInmatriculare, status);
	return 0;
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

void Service::setParking(int nr) {
	parking = nr;
}

int Service::intrareParcare(Car c) {
	if (c.getStatus())
		if (strcmp(c.getStatus(), "ocupat") == 0) {
			return -1;
		}
		else {
			int k = 0;
			for (int i = 0; i < r.dim(); i++)
				if (strcmp(getItemFromPos(i).getStatus(), "ocupat") == 0)
					k++;
			if (k >= parking) {
				n++;
				return -2;
			}
		}
	r.updateElem(c, c.getNumePosesor(), c.getNrInmatriculare(), "ocupat");
	n = 0;
	return 0;
}

int Service::iesireParcare(Car c) {
	if (strcmp(c.getStatus(), "ocupat") == 0) {
		r.updateElem(c, c.getNumePosesor(), c.getNrInmatriculare(), "liber");
		n= 0;
		return 0;
	}
	else {
		return -1;
	}
}