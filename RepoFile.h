#pragma once
#include "RepoTemplate.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <list>
#include "Car.h"

template<class T>class RepoFile :public RepoTemplate<Car>
{
private:
	const char* fis;
public:
	RepoFile();
	RepoFile(const char*);
	int addElem(const T&);
	int deleteElem(const T&);
	void updateElem(const T&, const T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFile();
};

template<class T>
RepoFile<T>::RepoFile() :RepoTemplate<Car>()
{
	fis = "";
}

template<class T>
RepoFile<T>::RepoFile(const char* fileName)
{
	loadFromFile(fileName);
}

template<class T>
void RepoFile<T>::loadFromFile(const char* fileName)
{
	RepoTemplate::clearElem();
	fis = fileName;
	ifstream f(fileName);
	char* nume = new char[10];
	char* numar = new char[10];
	char* status = new char[10];
	while (!f.eof())
	{
		f >> nume >> numar >> status;
		if (strcmp(nume, "") != 0)
		{
			Car e(nume, numar, status);
			RepoTemplate::addElem(e);
		}
	}
	delete[] nume;
	delete[] numar;
	delete[] status;
	f.close();
}

template<class T>
void RepoFile<T>::saveToFile()
{
	ofstream f(fis);
	list<Car>::iterator it;
	list<Car>elem = RepositoryTemplate::getAll();
	for (it = elem.begin(); it != elem.end(); ++it)
	{
		f << *it;
	}
	f.close();
}

template<class T>
RepoFile<T>::~RepoFile()
{

}

template<class T>
int RepoFile<T>::addElem(const T& e) {
	int r = RepoTemplate::addElem(e);
	if (r != -1) {
		saveToFile();
		return 0;
	}
	return -1;
}

template<class T>
int RepoFile<T>::deleteElem(const T& e) {
	int r = RepoTemplate::deleteElem(e);
	if (r != 0) {
		saveToFile();
		return 0;
	}
	else
		return -1;
}
template<class T>
void RepoFile<T>::updateElem(const T& e, const T n)
{
	RepoTemplate::updateElem(e, n);
	saveToFile();
}
