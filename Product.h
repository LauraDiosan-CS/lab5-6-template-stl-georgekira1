#ifndef LAB_7_PRODUCT_H
#define LAB_7_PRODUCT_H
#pragma once
#include<ostream>
#include <iostream>
using namespace std;

class Product {
private:
    int Id;
    char* name;
    int price;
public:
    Product();
    Product(int Id, char* name, int price);
    Product( const Product& p);
    ~Product();

    int getId();
    char* getName();
    int getPrice();
    void setId(int Id);
    void setName(char* a_name);
    void setPrice(int a_price);

    Product& operator=(const Product& p);
    bool operator==(const Product& p);
    friend ostream& operator<<(ostream &os, Product &p);
    friend istream& operator>>(istream &is, Product &p);


};


#endif //LAB_7_PRODUCT_H
