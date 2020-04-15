#ifndef LAB_7_REPOFILEBILLS_H
#define LAB_7_REPOFILEBILLS_H
#pragma once
#include<vector>
#include <cstring>
#include "Bills.h"
#include "Repo.h"
#include<fstream>


template <class T>
class RepoFileBills : public RepoSTL<T>
        {
private:
    vector <T> bills;
    char* fileNameIn;
    char* fileNameOut;
public:
    RepoFileBills();
    RepoFileBills(const char* fileNameIn, const char* fileNameOut);
    ~RepoFileBills();

    void addBill(T b);
    vector<T> getAllBills();
    int getSizeBills();
    void updateBillNumber(int value, int new_number);

    void setFileNameIn(const char* fileNameIn);
    void setFileNameOut(const char* fileNameOut);

    void loadFromFile();
    void saveToFile();
};

template  <class T>
RepoFileBills<T>:: RepoFileBills(){
    this->fileNameIn = nullptr;
    this->fileNameOut = nullptr;
}

template <class T>
RepoFileBills<T>:: RepoFileBills(const char* fileNameIn, const char* fileNameOut){
    this->fileNameIn = new char[strlen(fileNameIn) + 1];
    strcpy_s(this->fileNameIn, strlen(fileNameIn) + 1, fileNameIn);
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy(this->fileNameOut, fileNameOut);
    this->loadFromFile();
}

template  <class T>
void RepoFileBills<T>:: setFileNameIn(const char* fileNameIn){
    if (this->fileNameIn != nullptr)
    {
        delete[]this->fileNameIn;
    }
    this->fileNameIn = new char[strlen(fileNameIn)+1];
    strcpy(this->fileNameIn,  fileNameIn);
}

template <class T>
void RepoFileBills<T>:: setFileNameOut(const char* fileNameOut){
    if (this->fileNameOut != nullptr)
    {
        delete[]this->fileNameOut;
    }
    this->fileNameOut = new char[strlen(fileNameOut) + 1];
    strcpy(this->fileNameOut, fileNameOut);
}

template <class T>
void RepoFileBills<T>:: loadFromFile(){
    if (this->fileNameIn != nullptr)
    {
        this->bills.clear();
        ifstream f(this->fileNameIn);
        int value;
        int number;
        while (!f.eof())
        {
            f >> value  >> number;
            if (number > 0)
                {
                    this->addBill(Bills(value, number));
                }
        }

        f.close();
    }
}

template <class T>
void RepoFileBills<T>:: saveToFile(){
    if (this->fileNameOut != nullptr)
    {
        ofstream f(this->fileNameOut);
        for (int i = 0; i < this->bills.size(); i++)
        {
            f << this->bills[i] << endl;
        }
        f.close();
    }
}

template <class T>
void RepoFileBills<T>:: addBill(T b){
    this->bills.push_back(b);
    this->saveToFile();
}

template <class T>
vector<T> RepoFileBills<T>::getAllBills(){
    return this->bills;
}

template  <class T>
void RepoFileBills<T>:: updateBillNumber(int value, int new_number){
    for (int i = 0; i<bills.size(); i++)
        {
            if (bills[i].getValue() == value)
            {bills[i].setNumber(new_number);
             this->saveToFile();
            }
        }
}

template <class T>
int RepoFileBills<T>:: getSizeBills() {
    return this->bills.size();
}

template <class T>
RepoFileBills<T>:: ~RepoFileBills(){
    this->bills.clear();
}






#endif //LAB_7_REPOFILEBILLS_H












