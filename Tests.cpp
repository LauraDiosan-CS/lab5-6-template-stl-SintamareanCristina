#include "Car.h"
#include "Repo.h"
#include "Service.h"
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include "Tests.h"
#include <assert.h>
#include <string.h>

void testEntity()
{
    Car x;
    assert(x.getNumePosesor() == NULL);
    assert(x.getStatus() == NULL);
    assert(x.getNrInmatriculare() == NULL);

    Car c("Ana", "CJ20ana", "ocupat");
    assert(strcmp(c.getNumePosesor(), "Ana") == 0);
    assert(strcmp(c.getNrInmatriculare(), "CJ20ana") == 0);
    assert(strcmp(c.getStatus(), "ocupat") == 0);

    c.setNumePosesor("Maria");
    assert(strcmp(c.getNumePosesor(), "Maria") == 0);
    c.setNrInmatriculare("BH20mar");
    assert(strcmp(c.getNrInmatriculare(), "BH20mar") == 0);
    c.setStatus("liber");
    assert(strcmp(c.getStatus(), "liber") == 0);

    Car q("Maria", "BH20mar", "liber");
    assert(c == q);

    Car c2(c);
    assert(c == c2);

    Car a("Briana", "CJ09bri", "liber");
    Car b("Cristina", "CJ08crs", "ocupat");
    a = b;
    assert(strcmp(a.getNumePosesor(), "Cristina") == 0);
    assert(strcmp(a.getNrInmatriculare(), "CJ08crs") == 0);
    assert(strcmp(a.getStatus(), "ocupat") == 0);
}

void testRepo() {
    Car p1("Ana", "CJ20mar", "liber");
    Car p2("Bogdan", "CJ16bgd", "ocupat");
    Car p3("Mihai", "CJ11mih", "liber");
    Repo rep;

    assert(rep.dim() == 0);
    rep.addElem(p1);
    rep.addElem(p2);
    rep.addElem(p3);
    assert(rep.dim() == 3);

    rep.delElem(p3);
    assert(rep.dim() == 2);

    list<Car>elem;
    elem = rep.getAll();
    assert(elem.front() == p1);
    assert(elem.back() == p2);
    assert(rep.getItemFromPos(1) == p2);

    rep.updateElem(p1, "Ana", "CJ20mar", "ocupat");
    //assert(rep.findElem(p1) == false);
    assert(strcmp(rep.getItemFromPos(1).getStatus(), "ocupat") == 0);
}

void testService() {
    Service s;
    Car c1("Ana", "CJ19aaa", "ocupat");
    s.addElem(c1);
    assert(s.dim() == 1);
    Car c2("Alex", "BV10axl", "liber");
    s.addElem(c2);
    assert(s.dim() == 2);

    s.delElem(c1);
    assert(s.dim() == 1);

    Car c3("Maria", "BH09mar", "ocupat");
    s.addElem(c3);
    list<Car>elem;
    elem = s.getAll();
    assert(elem.front() == c2);
    assert(elem.back() == c3);
    assert(s.getItemFromPos(1) == c3);

    s.updateElem(c2, "Alex", "BV10axl", "ocupat");
    assert(s.findElem(c2) == false);
}

void tests() {
    testEntity();
    testRepo();
    testService();
    cout << "Testele s-au rulat" << endl;
}