#include "Car.h"
#include <string.h>
#include <cstddef>
#include <ostream>

using namespace std;

// Constructor
// In: -
// Out: an empty object of type Car

Car::Car() {
	this->numePosesor = NULL;
	this->nrInmatriculare = NULL;
	this->status = NULL;
}


// Constructor with parameters

Car::Car(const char* numePosesor, const char* nrInmatriculare, const char* status)
{
	if (numePosesor) {
		this->numePosesor = new char[strlen(numePosesor) + 1];
		strcpy_s(this->numePosesor, strlen(numePosesor) + 1, numePosesor);
	}
	if (status) {
		this->status = new char[strlen(status) + 1];
		strcpy_s(this->status, strlen(status) + 1, status);
	}
	if (nrInmatriculare) {
		this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
		strcpy_s(this->nrInmatriculare, strlen(nrInmatriculare) + 1, nrInmatriculare);
	}
}


// Copy constructor

Car::Car(const Car& c)
{
	if (c.numePosesor) {
		this->numePosesor = new char[strlen(c.numePosesor) + 1];
		strcpy_s(this->numePosesor, 1 + strlen(c.numePosesor), c.numePosesor);
	}
	if (c.nrInmatriculare){
		this->nrInmatriculare = new char[strlen(c.nrInmatriculare) + 1];
		strcpy_s(this->nrInmatriculare, 1 + strlen(c.nrInmatriculare), c.nrInmatriculare); }
	if (c.status) {
		this->status = new char[strlen(c.status) + 1];
		strcpy_s(this->status, 1 + strlen(c.status), c.status);
	}
}


Car::~Car()
{
	if (this->numePosesor)
	{
		delete[] this->numePosesor;
		this->numePosesor = NULL;
	}
	if (this->nrInmatriculare) {
		delete[] this->nrInmatriculare;
		this->nrInmatriculare = NULL;
	}
	if (this->status) {
		delete[] this->status;
		this->status = NULL;
	}
}


// getter

char* Car::getNumePosesor() {
	return this->numePosesor;
}


// getter

char* Car::getNrInmatriculare() {
	return this->nrInmatriculare;
}


// getter

char* Car::getStatus() {
	return this->status;
}


// setter

void Car::setNumePosesor(const char* n) {
	if (numePosesor) delete[]numePosesor;
	numePosesor = new char[strlen(n) + 1];
	strcpy_s(numePosesor, strlen(n) + 1, n);
}


// setter

void Car::setNrInmatriculare(const char* nrInmatriculare) {
	if (nrInmatriculare) delete[]nrInmatriculare;
	this->nrInmatriculare = new char[strlen(nrInmatriculare) + 1];
	strcpy_s(this->nrInmatriculare, strlen(nrInmatriculare) + 1, nrInmatriculare);
}


// setter

void Car::setStatus(const char* status) {
	if (status) delete[]status;
	this->status = new char[strlen(status) + 1];
	strcpy_s(this->status, strlen(status) + 1, status);
}


// assignment operator

Car& Car::operator =(const Car& e) {
	if (this == &e) return *this; 
	if (e.numePosesor) {
		if (this->numePosesor)delete[]this->numePosesor;
		this->numePosesor = new char[strlen(e.numePosesor) + 1];
		strcpy_s(this->numePosesor, strlen(e.numePosesor) + 1, e.numePosesor);
	}
	if (e.status) {
		if (this->status)delete[]this->status;
		this->status = new char[strlen(e.status) + 1];
		strcpy_s(this->status, strlen(e.status) + 1, e.status);
	}
	if (e.nrInmatriculare) {
		if (this->nrInmatriculare)delete[]this->nrInmatriculare;
		this->nrInmatriculare = new char[strlen(e.nrInmatriculare) + 1];
		strcpy_s(this->nrInmatriculare, strlen(e.nrInmatriculare) + 1, e.nrInmatriculare);
	}
	return *this;
}


// comparator

bool Car::operator==(const Car& p) {
	return ((strcmp(this->numePosesor, p.numePosesor) == 0) and (strcmp(this->nrInmatriculare, p.nrInmatriculare) == 0) and (strcmp(this->status, p.status) == 0));
}

//pt afisare
ostream& operator<<(ostream& os, const Car& p)
{
	os << "Nume posesor: " << p.numePosesor << ", nr inmatriculare: " << p.nrInmatriculare << ", status: " << p.status;
	return os;
}