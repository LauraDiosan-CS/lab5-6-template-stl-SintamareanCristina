#include "Repo.h"
#include "RepoFile.h"
#include <fstream>
#include <string.h>
#include <list>
#include "Car.h"
#include "Repo.cpp"

class RepoFile : public Repo {
private:
	const char* fis;
public:
	RepoFile();  RepoFile(const char* fileName) {
		fis = fileName;
		ifstream f(fileName);
		string linie;
		char* numePosesor = new char[30];
		char* nrInmatriculare = new char[15];
		char* status = new char[10];
		while (!f.eof()) {
			f >> numePosesor >> nrInmatriculare >> status;
			if (numePosesor != "") {
				Car c(numePosesor, nrInmatriculare, status);
				addElem(c);
			}
		}
		delete[] numePosesor;
		delete[] nrInmatriculare;
		delete[] status;
		f.close();
	}

	~RepoFile() {
	}

	void loadFromFile(const char* fileName)
	{
		fis = fileName;
		ifstream f(fileName);
		char* numePosesor = new char[30];
		char* nrInmatriculare = new char[15];
		char* status = new char[10];
		while (!f.eof()) {
			f >> numePosesor >> nrInmatriculare >> status;
			if (strcmp(numePosesor, "") != 0) {
				Car s(numePosesor, nrInmatriculare, status);
				addElem(s);
			}
		}
		delete[] numePosesor;
		delete[] nrInmatriculare;
		delete[] status;
		f.close();
	};

	int addElem(Car c)
	{
		list<Car>::iterator it;
		int ok = 1;
		for (it = elem.begin(); it != elem.end(); it++)
			if (strcmp((*it).getNrInmatriculare(), c.getNrInmatriculare()) == 0)
				ok = 0;
		it = find(elem.begin(), elem.end(), c);
		if (it == elem.end() and ok == 1)
		{
			addElem(c);
			saveToFile();
			return 0;
		}
		return -1;
	}

	void updateElem(Car c, const char* numePosesor, const char* nrInmatriculare, const char* status)
	{
		list<Car>::iterator it;
		it = find(elem.begin(), elem.end(), c);
		if (it != elem.end())
		{
			updateElem(c, numePosesor, nrInmatriculare, status);
		}
		saveToFile();
	}

	int delElem(Car c)
	{
		list<Car>::iterator it;
		it = find(elem.begin(), elem.end(), c);
		if (it != elem.end())
		{
			delElem(*it);
			saveToFile();
			return 0;
		}
		else
			return -1;
	}

	void saveToFile()
	{
		ofstream f(fis);
		for (int i = 0; i < dim(); i++)
			if (i == dim() - 1)
				f << getItemFromPos(i).getNumePosesor() << " " << getItemFromPos(i).getNrInmatriculare() << " " << getItemFromPos(i).getStatus();
			else
				f << getItemFromPos(i);
		f.close();
	}
};