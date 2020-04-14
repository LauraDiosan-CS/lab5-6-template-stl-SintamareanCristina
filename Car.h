#pragma once
#include <ostream>
#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    char* numePosesor;
    char* nrInmatriculare;
    char* status;
public:
    Car();
    Car(const char* numePosesor, const char* nrInmatriculare, const char* status);
    Car(const Car& c);
    ~Car();
    char* getNumePosesor();
    char* getNrInmatriculare();
    char* getStatus();
    void setNumePosesor(const char* n);
    void setNrInmatriculare(const char* nrInmatriculare);
    void setStatus(const char* status);
    Car& operator=(const Car& e);
    bool operator==(const Car& p);
    friend ostream& operator<<(ostream& os, const Car& p);
    friend istream& operator>>(istream&, Car&);

};
