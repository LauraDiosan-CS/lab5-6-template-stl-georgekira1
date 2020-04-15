#ifndef LAB_7_BILLS_H
#define LAB_7_BILLS_H
#pragma once
#include <iostream>

using namespace std;

class Bills {
private :
    int value;
    int number;
public:
    Bills();
    Bills(int value, int number);
    Bills(const Bills& b);
    ~Bills();

    int getValue();
    int getNumber();
    void setValue(int a_value);
    void setNumber(int a_number);

    Bills& operator=(const Bills& b);
    bool operator==(const Bills& b);
    friend ostream& operator<<(ostream &os, Bills &b);
    friend istream& operator>>(istream &is, Bills &b);

};


#endif //LAB_7_BILLS_H



















