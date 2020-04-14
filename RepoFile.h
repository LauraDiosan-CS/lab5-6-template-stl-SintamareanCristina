#pragma once
#include "Repo.h"
#include <fstream>
#include <string.h>
#include <iostream>
#include <list>
#include "Car.h"

class RepoFile :
	public Repo {
private:
	const char* fis;
public:
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	~RepoFile();
	int addElem(Car c);
	int delElem(Car c);
	void updateElem(Car c, const char* numePosesor, const char* nrInmatriculare, const char* status);
	void saveToFile();
};
