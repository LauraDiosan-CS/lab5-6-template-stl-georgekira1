#include "Bills.h"
#include <cstring>
#include <iostream>

using namespace std;

Bills:: Bills(){
    this->value = 0;
    this->number = 0;
}

Bills:: Bills(int value, int number){
    this->value = value;
    this->number = number;
}

Bills:: Bills(const Bills& b){
    this->value = b.value;
    this->number = b.number;
}


Bills:: ~Bills() =  default;

int Bills:: getValue(){
    return this->value;
}

int Bills:: getNumber(){
    return this->number;
}

void Bills:: setValue(int a_value){
    this->value = a_value;
}

void Bills:: setNumber(int a_number){
    this->number = a_number;
}

Bills& Bills:: operator=(const Bills& b){
    this->setValue(b.value);
    this->setNumber(b.number);
    return *this;
}

bool Bills:: operator==(const Bills& b){
    return (this->value == b.value) && (this->number == b.number);
}

ostream& operator<< (ostream &os, Bills &b){
    os << b.value << " " << b.number << endl;
    return os;
}

istream& operator>>(istream& is, Bills& b){
    cout << " is >> b " << endl;
    cout << "Value = ";
    is >> b.value;
    cout << "Number = ";
    is >> b.number ;

    cout <<b.value << "  " <<b.number<<endl;
    return is;
}

