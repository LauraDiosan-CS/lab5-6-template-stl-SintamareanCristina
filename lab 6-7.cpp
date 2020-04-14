// lab 6-7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include "Service.h"
#include "Tests.h"
#include "UI.h"
#include "RepoFile.h"
using namespace std;

int main() {
	Repo repo;
	Service s(repo); UI ui(s); RepoFile repoFile("Masini.txt");
	tests();
	ui.run();
	return 0;
}
