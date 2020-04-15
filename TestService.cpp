#include "TestService.h"
#include <cassert>
#include <cstring>
#include<iostream>

using namespace std;

TestService::TestService() {
    char* name1 = new char[10];
    strcpy(name1, "twix");

    char* name2 = new char[10];
    strcpy(name2, "milka");

    Product p1(1, name1, 1);
    Product p2(2, name2, 2);

 s.addProduct(1, name1, 1);
 s.addProduct(2, name2, 2);

}

void TestService::testAll(){
    this->testAddProduct();
    this->testAddBill();
    this->testUpdateProductPrice();
    this->testGetPrice();
    this->testUpdateBillsNumber();
    this->testGetWantedProduct();
    this->testGetChange();
}

void TestService::testAddProduct() {
    char* name3 = new char[10];
    strcpy(name3, "coconut");

    s.addProduct(3, name3, 3);

    assert(s.getSize() == 3);
}

void TestService::testAddBill(){
    s.addBill(5, 10);

    assert(s.getSizeBills() == 1);
}

void TestService::testUpdateProductPrice() {
    Product updated_product;
    for(int i = 0; i < s.getSize(); i++)
        {
            if (s.getAll()[i].getId() == 3)
                updated_product = s.getAll()[i];
            s.updateProductPrice(3, 4);
        }

    assert(updated_product.getPrice() == 4);

}

void TestService:: testGetPrice(){

    assert(s.getPrice(3) == 4);

}


void TestService::testUpdateBillsNumber() {
    Bills updated_bill;
    s.addBill(5, 10);
    for (int i = 0; i<s.getSizeBills(); i++)
        {
            if (s.getAllBills()[i].getValue() == 5)
                updated_bill = s.getAllBills()[i];
            s.updateBillsNumber(5, 20);
        }

    assert (updated_bill.getNumber() == 20);
}

void TestService::testGetWantedProduct() {
    char* name1 = new char[10];
    strcpy(name1, "twix");

    assert(s.getWantedProduct(1) == Product(1, name1, 1));
}

void TestService::testGetChange(){
    assert (s.getChange(1, 6) == 5);
}