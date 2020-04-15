#ifndef LAB_7_UI_H
#define LAB_7_UI_H

#pragma once
#include "Product.h"
#include "RepoFile.h"
#include "Service.h"
#include <cstring>
#include <vector>

using namespace std;

class UI {

private: Service s;
    void showMenu();
    void handleAddProduct();
    void handleDeleteProduct();
    void handleShowAll();
    void buy();


public:
    UI();
    UI(Service& S);
    ~UI();
    void Menu();

};


#endif //LAB_7_UI_H










