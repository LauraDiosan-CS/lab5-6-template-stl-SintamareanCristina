#include "UI.h"
#include "Service.h"
#include <iostream>
#include <iterator>
#include <list>

using namespace std;

//constructor
UI::UI()
{
	this->s;
}

//destructor
UI::~UI()
{
}

//afisare meniu
void UI::printMenu()
{
	cout << endl;
	cout << "1. Adaugare." << endl;
	cout << "2. Afisare" << endl;
	cout << "3. Update" << endl;
	cout << "4. Stergere" << endl;
	cout << "5. Iesire." << endl;
	cout << endl;
}

//adaugare element 
void UI::addElem(Service& s)
{
	char nume[20], nr[10], status[7];
	int n = 0;
	cout << "Nume: ";
	cin >> nume;
	cout << "Numar inmatriculare: ";
	cin >> nr;
	cout << "Status [liber/ocupat]: ";
	cin >> status;
	Car c(nume, nr, status);
	if (strcmp(status, "ocupat") == 0) cout << "Statusul nu poate fi ocupat" << endl;
	s.addElem(c); n++;
	cout << "Added!"<<endl;
	cout << endl;
}

//afisare toate elemente
void UI:: getAll(Service& s)
{
	cout << endl << "Masini: " << endl;
	list<Car>elem;
	elem = s.getAll();
	copy(elem.begin(), elem.end(), std::ostream_iterator<Car>(std::cout, "\n"));
}

//stergere element 
void UI::delElem(Service& s)
{
	cout << "Sterge masina cu numarul: ";
	int i; cin >> i; int n = s.dim();
	s.delElem(s.getItemFromPos(i - 1)); n -= 1;
	cout << "Deleted!"<<endl;
	cout << endl;
}

//modificare element de tip Project
void UI::updateElem(Service& s)
{
	cout << "Update la masina cu numarul: "; int i; cin >> i;
	Car c = s.getItemFromPos(i - 1);
	cout << "Nume: "; char  nume[20];  cin >> nume;
	cout << "Nr inmatriculare: "; char nr[10];  cin >> nr;
	cout << "Status [liber/ocupat]: "; char status[10];  cin >> status;
	s.updateElem(c, nume, nr, status);
	cout << "Updated!"<<endl;
	cout << endl;
}