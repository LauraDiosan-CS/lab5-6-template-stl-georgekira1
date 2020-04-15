#include "Product.h"
#include <cstring>
#include <iostream>

using namespace std;

Product:: Product() {
    this->Id = 0;
    this->name = nullptr;
    this->price = 0;
}

Product:: Product(int Id, char* name, int price){
    this->Id = Id;
    this->price = price;
    this->name = new char[strlen(name)+1];
    strcpy(this->name, name);
}

Product::  Product( const Product& p){
    this->Id = p.Id;
    this->name = new char [strlen(p.name) + 1];
    strcpy(this->name, p.name);
    this->price = p.price;
}

Product:: ~Product(){
    if (this->name != nullptr)
    {
        delete [] this->name;
        this->name = nullptr;
    }
}

int Product:: getId() {
    return this->Id;
}

char* Product:: getName(){
    return this->name;
}

int Product:: getPrice(){
    return this->price;
}

void Product:: setId(int Id){
    this->Id = Id;
}

void Product:: setName(char* a_name){
    if (this->name != nullptr)
    {
        delete [] this->name;
        this->name = nullptr;
    }
    this->name = new char[strlen(a_name)+1];
    strcpy(this->name, a_name);
}

void Product:: setPrice(int a_price){
    this->price = a_price;
}

Product& Product:: operator=(const Product& p){
    this->setId(p.Id);
    this->setName(p.name);
    this->setPrice(p.price);
    return *this;
}

bool Product:: operator==(const Product& p){
    return (this->Id == p.Id) && (strcmp(this->name, name) == 0) && (this->price == p.price);
}

ostream& operator<< (ostream &os, Product &p){
    os << p.Id << " " << p.name << "  " << p.price << endl;
    return os;
}

istream& operator>>(istream& is, Product& p){
    cout << " is >> p " << endl;
    cout << "Id = ";
    is >> p.Id;
    cout << "name = ";
    is >> p.name ;
    cout << "price = ";
    is >> p.price ;

    cout <<p.Id << "  " <<p.name << " "<<p.price<<endl;
    return is;
}

