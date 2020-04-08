#include "Repo.h"
#include "RepoFile.h"
#include <fstream>
#include <string.h>
#include <list>
#include "Car.h"

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
		f.close();
	}

	~RepoFile() {
	}

	void RepoFile(); void loadFromFile(const char* fileName)
	{
		delAll;
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
		f.close();
	};
};

