#ifndef LAB_7_SERVICE_H
#define LAB_7_SERVICE_H

#pragma once
#include "Product.h"
#include "Bills.h"
#include "RepoFile.h"
#include "RepoFileBills.h"
#include <vector>
using namespace std;

class Service {

private: RepoFile<Product> r;
         RepoFileBills<Bills> b;


public: Service ();
        Service(RepoFile<Product> &r, RepoFileBills<Bills> &b);
        ~Service();

        void setRepoFile(RepoFile<Product> r, RepoFileBills<Bills> b);

        void addProduct(int Id, char* name, int price );
        void addBill(int value, int number);
        void deleteProduct( int Id, char* name, int price);
        int getSize();
        int getSizeBills();
        int getPrice(int Id);
        void updateProductPrice(int Id, int price);
        void updateBillsNumber(int value, int new_number);
        vector <Product> getAll();
        vector <Bills> getAllBills();
        Product getWantedProduct(int Id);
        int getChange(int Id, int money);
};









#endif //LAB_7_SERVICE_H
