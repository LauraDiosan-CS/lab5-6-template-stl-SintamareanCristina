#include "Car.h"
#include "Repo.h"
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
    
    Car c("a", "24aaabc", "ocupat");
    assert(strcmp(c.getNumePosesor(), "a") == 0);
    assert(strcmp(c.getNrInmatriculare(), "24aaabc") == 0);
    assert(strcmp(c.getStatus(), "ocupat") == 0);
    
    c.setNumePosesor("aaa");
    assert(strcmp(c.getNumePosesor(), "aaa") == 0);
    c.setNrInmatriculare("24aaab");
    assert(strcmp(c.getNrInmatriculare(), "24aaab") == 0);
    c.setStatus("liber");
    assert(strcmp(c.getStatus(), "liber") == 0);
    
    Car q("aaa", "24aaab", "liber");
    assert(c == q);
  
    Car c2(c);
    assert(c == c2);
    
    Car a("b", "20ababc", "liber");
    Car b("c", "19ababbc", "ocupat");
    a = b;
    assert(a.getNumePosesor() == "c");
    assert(a.getNrInmatriculare() == "19ababbc");
    assert(a.getStatus() == "ocupat");
}

void testRepo() {
    Car p1("b", "20ababc", "liber");
    Car p2("c", "19ababbc", "ocupat");
    Repo rep;
    assert(rep.dim() == 0);
    rep.addElem(p1);
    rep.addElem(p2);
    assert(rep.dim() == 2);
    list<Car>elem;
    elem = rep.getAll();
    assert(elem.front() == p1);
    assert(elem.back() == p2);
}

void tests() {
    testEntity();
    testRepo();
    cout << "Testele s-au rulat" << endl;
}