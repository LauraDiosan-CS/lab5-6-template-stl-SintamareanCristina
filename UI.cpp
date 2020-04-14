#include "UI.h"
#include "Service.h"
#include <iostream>
#include <iterator>
#include <list>

using namespace std;

UI::UI()
{
}

//destructor
UI::~UI()
{
}

UI::UI(const Service& serv) {
	this->s = serv;
}

//afisare meniu
void UI::printMenu()
{
	cout << endl;
	cout << "1. Adaugare." << endl;
	cout << "2. Afisare" << endl;
	cout << "3. Update" << endl;
	cout << "4. Stergere" << endl;
	cout << "5. Intrare in parcare" << endl;
	cout << "6. Iesire din parcare" << endl;
	cout << "7. Numarul cu care s-a depasit capacitatea" << endl;
	cout << "8. Iesire." << endl;
	cout << endl;
}

//adaugare element 
void UI::addElem()
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
	if (strcmp(status, "liber") == 0 or strcmp(status, "ocupat") == 0) {
		int rez = s.addElem(c);
		if (rez == -1)
			cout << "Masina nu poate fi adaugata" << endl;
		else if (rez == -2)
			cout << "Parcarea e plina" << endl;
		else if (rez == 0)
			cout << "Added!" << endl;
	}
}

//afisare toate elemente
void UI::getAll()
{
	cout << endl << "Masini: " << endl;
	list<Car>elem;
	elem = s.getAll();
	copy(elem.begin(), elem.end(), std::ostream_iterator<Car>(std::cout, "\n"));
}

//stergere element 
void UI::delElem()
{
	cout << "Sterge masina cu numarul: ";
	int i; cin >> i; int n = s.dim();
	Car c = s.getItemFromPos(i - 1);
	if (strcmp(c.getStatus(), "liber") == 0 or strcmp(c.getStatus(), "ocupat") == 0)
	{
		int rez = s.delElem(c);
		if (rez == -1)
			cout << "Masina nu exista" << endl;
		else if (rez == 0)
			cout << "Deleted!" << endl;
		else if (rez == -2)
			cout << "Masina se afla in parcare" << endl;
	}
}

//modificare element de tip Project
void UI::updateElem()
{
	cout << "Update la masina cu numarul: "; int i; cin >> i;
	Car c = s.getItemFromPos(i - 1);
	cout << "Nume: "; char  nume[20];  cin >> nume;
	cout << "Nr inmatriculare: "; char nr[10];  cin >> nr;
	cout << "Status [liber/ocupat]: "; char status[10];  cin >> status;
	if (strcmp(status, "liber") == 0 or strcmp(status, "ocupat") == 0)
	{
		int rez = s.updateElem(c, nume, nr, status);
		if (rez == -2)
			cout << "Statusul nu poate fi -ocupat-" << endl;
	}
	else cout << "Updated!" << endl;
	cout << endl;
}

void UI::intrareParcare() {
	char* l = new char[20];
	cout << "Numar inmatriculare: ";
	cin >> l;
	Car c;
	for (int i = 0; i < s.dim(); i++)
		if (strcmp(s.getItemFromPos(i).getNrInmatriculare(), l) == 0)
			c = s.getItemFromPos(i);
	//delete l;
	if (s.findElem(c) == true) {
		int rez = s.intrareParcare(c);
		if (rez == -1)
			cout << "Masina se afla in parcare" << endl;
		else if (rez == -2)
			cout << "Parcarea e plina" << endl;
		else if (rez == 0)
			cout << "Done!" << endl;
	}
	else
		cout << "Masina nu exista" << endl;
}

void UI::iesireParcare() {
	char* l = new char[20];
	cout << "Numar inmatriculare: ";
	cin >> l;
	Car c;
	for (int i = 0; i < s.dim(); i++)
		if (strcmp(s.getItemFromPos(i).getNrInmatriculare(), l) == 0)
			c = s.getItemFromPos(i);
	//delete l;
	if (s.findElem(c) == true) {
		int rez = s.iesireParcare(c);
		if (rez == -1)
			cout << "Masina nu se afla in parcare" << endl;
		else if (rez == 0)
			cout << "Done!" << endl;
	}
	else
		cout << "Masina nu exista" << endl;
}

void UI::run() {
	bool k = true;
	cout << "Capacitate parcare: ";
	int nr;
	cin >> nr;
	s.setParking(nr);
	printMenu();
	while (k)
	{
		int option = 0;
		cin >> option;
		if (option == 1)
		{
			addElem();
			printMenu();
			continue;
		}
		if (option == 2)
		{
			getAll();
			printMenu();
			continue;
		}
		if (option == 3)
		{
			updateElem();
			printMenu();
			continue;
		}
		if (option == 4)
		{
			delElem();
			printMenu();
			continue;
		}
		if (option == 5) {
			intrareParcare();
			printMenu();
			continue;
		}
		if (option == 6) {
			iesireParcare();
			printMenu();
			continue;
		}
		if (option == 7) {
			cout << endl;
			cout << s.number << endl;
			printMenu();
			continue;
		}
		if (option == 8)
			k = false;
	}
}