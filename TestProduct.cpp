#include "TestProduct.h"
#include <cassert>
#include <cstring>
#include<iostream>

using namespace std;

TestProduct:: TestProduct() {
    char* name1 = new char[10];
    strcpy(name1, "twix");
    char* name2 = new char[10];
    strcpy(name2, "milka");
    Product p1(1, name1, 1);
    Product p2(2, name2, 2);
    products.push_back(p1);
    products.push_back(p2);
}

void TestProduct:: testAll(){
    this->testGetId();
    this->testGetName();
    this->testGetPrice();
    this->testSetId();
}

void TestProduct::testGetId() {
    for (int i = 0; i<products.size(); i++)
    {
        assert(products[i].getId() == i+1);
    }
}

void TestProduct:: testGetName(){
    assert(strcmp(products[0].getName(), "twix") == 0);
    assert(strcmp(products[1].getName(), "milka") == 0);
}

void TestProduct::testGetPrice() {
    for (int i = 0; i<products.size(); i++)
    {
        assert(products[i].getPrice() == i+1);
    }
}

void TestProduct:: testSetId(){
    products[0].setId(2);
    assert(products[0].getId() == 2);
}