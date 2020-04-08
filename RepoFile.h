#pragma once
#include "Repo.h"
#include <fstream>
#include <string.h>
#include <list>
#include "Car.h"

class RepoFile
{
private:
	const char* fis;
public:
	RepoFile(const char* fileName);
	void loadFromFile(const char* fileName);
	~RepoFile();
};

