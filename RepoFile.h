#ifndef LAB_7_REPOFILE_H
#define LAB_7_REPOFILE_H

#pragma once
#include<vector>
#include <cstring>
#include "Product.h"
#include "Repo.h"
#include<fstream>

template <class T>
class RepoFile : public RepoSTL<T>
        {
    private:
        vector <T> products;
        char* fileNameIn;
        char* fileNameOut;

    public:
        RepoFile();
        RepoFile(const char* fileNameIn, const char* fileNameOut);
        ~RepoFile();

        void addProduct(T p);
        vector<T> getAll();
        void deleteProduct(T p);
        Product getProduct(int Id);
        void updateProductPrice(int Id, int price);
        int findProduct(T p);
        int getSize();

        void setFileNameIn(const char* fileNameIn);
        void setFileNameOut(const char* fileNameOut);

        void loadFromFile();
        void saveToFile();

};

template <class T>
RepoFile<T>:: RepoFile() {
    this->fileNameIn = nullptr;
    this->fileNameOut = nullptr;
}

template <class T>
RepoFile<T>:: RepoFile(const char* fileNameIn, const char* fileNameOut){
    this->fileNameIn = new char[strlen(fileNameIn) + 1];
    strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
    this->loadFromFile();
}

template <class T>
void RepoFile<T>:: setFileNameIn(const char* fileNameIn){
    if (this->fileNameIn != nullptr)
    {
        delete[]this->fileNameIn;
    }
    this->fileNameIn = new char[strlen(fileNameIn)+1];
    strcpy(this->fileNameIn,  fileNameIn);
}


template <class T>
void RepoFile<T>:: setFileNameOut(const char* fileNameOut){
    if (this->fileNameOut != nullptr)
    {
        delete[]this->fileNameOut;
    }
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy_s(this->fileNameOut, strlen(fileNameOut) + 1, fileNameOut);
}

template <class T>
void RepoFile<T>:: loadFromFile(){
    if (this->fileNameIn != nullptr)
    {
        this->products.clear();
        ifstream f(this->fileNameIn);
        int Id;
        char* name = new char[20];
        int price;
        while (!f.eof())
        {
            f >> Id  >> name >>  price;
            if (strlen(name) > 0)
            {
                this->addProduct(Product(Id, name, price));
            }
        }
        delete[] name;
        f.close();
    }
}

template <class T>
void RepoFile<T>:: saveToFile(){
    if (this->fileNameOut != nullptr)
    {
        ofstream f(this->fileNameOut);
        for (int i = 0; i < this->products.size(); i++)
        {
            f << this->products[i] << endl;
        }
        f.close();
    }
}

template <class T>
void RepoFile<T>:: addProduct(T p){
    this->products.push_back(p);
    this->saveToFile();
}

template <class T>
vector <T> RepoFile<T>:: getAll(){
    return this->products;
}

template  <class T>
int RepoFile<T>:: getSize(){
    return this->products.size();
}

template <class T>
int RepoFile<T>::findProduct(T p) {
    for (int i = 0; i < products.size(); i++)
    {
        if (products[i] == p)
            return i;
    }
    return -1;
}

template <class T>
void RepoFile<T>:: deleteProduct(T p){
    int start_contor = findProduct(p);
    for (int i = start_contor; i <= this->products.size()-2; i++)
        products[i] = products[i+1];
    products.pop_back();
    this->saveToFile();
}

template <class T>
Product RepoFile<T>:: getProduct(int Id) {
        for (int i = 0; i<products.size(); i++)
        {
            if (Id == products[i].getId())
                return products[i];
        }
    }

template <class T>
void RepoFile<T>::updateProductPrice(int Id, int price) {
   for (int i = 0; i< products.size(); i++)
        {
            if (products[i].getId() == Id) {
                products[i].setPrice(price);
                this->saveToFile();
            }
        }


}

template <class T>
RepoFile<T>:: ~RepoFile(){
    this->products.clear();
}



#endif //LAB_7_REPOFILE_H








