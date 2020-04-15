#ifndef LAB_7_REPO_H
#define LAB_7_REPO_H
#pragma once
#include "Product.h"
#include "Bills.h"
#include <vector>

template <class T>
class RepoSTL {

protected: vector <T> products;
           vector <T> bills;

public:  RepoSTL();
        ~RepoSTL();

    virtual void addProduct(T p);
    void updateProduct(int position, T p);
    int findProduct(T p);
    void deleteProduct(T p);
    vector<T> getAll();
    int getSize();

};

template <class T>
RepoSTL<T>:: RepoSTL()= default;

template <class T>
RepoSTL<T>::~RepoSTL() {
    this->products.clear();
}

template <class T>
void RepoSTL<T>:: addProduct(T p){
    this->products.push_back(p);
}

template <class T>
int RepoSTL<T>:: findProduct(T p){
    for (int i = 0; i < this->products.size(); i++)
    {
        if (products[i] == p)
            return i;
    }
    return 0;
}

template <class T>
void RepoSTL<T>:: deleteProduct(T p){
    int start_contor = findProduct(p);
    for (int i = start_contor; i <= this->products.size()-2; i++)
        products[i] = products[i+1];
    this->products.pop_back();

}

template <class T>
void RepoSTL<T>:: updateProduct (int position, T p){

    products[position] = p;
}

template <class T>
vector<T> RepoSTL<T>:: getAll(){
    return this-> products;

}

template <class T>
int RepoSTL<T>::getSize()
{
    return this->products.size();
}

#endif //LAB_7_REPO_H
