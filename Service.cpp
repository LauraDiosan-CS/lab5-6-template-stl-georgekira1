#include "Service.h"


Service:: Service() = default;

Service:: Service(RepoFile<Product> &r, RepoFileBills<Bills> &b){
    this->r = r;
    this->b = b;
}

Service:: ~Service() = default;

void Service::setRepoFile(RepoFile<Product> r, RepoFileBills <Bills> b)
{
    this->r = r;
    this->b = b;
}

void Service:: addProduct(int Id, char* name, int price) {
    this->r.addProduct(Product(Id, name, price));
}

void Service:: addBill(int value, int number){
    this->b.addBill(Bills(value, number));
}

void Service:: deleteProduct(int Id, char* name, int price){
    return this->r.deleteProduct(Product(Id, name, price));
}

int Service:: getPrice(int Id){
    for (int i = 0; i < r.getSize(); i++)
        {
            if (Id == r.getAll()[i].getId())
                return r.getAll()[i].getPrice();
        }
    return -1;
}

vector <Product> Service:: getAll(){
    return r.getAll();
}

int Service :: getSize(){
    return r.getSize();
}

int Service:: getSizeBills(){
    return b.getSizeBills();
}

void Service::updateProductPrice(int Id, int price) {
    return this->r.updateProductPrice(Id, price);
}

void Service:: updateBillsNumber(int value, int new_number){
    return this->b.updateBillNumber(value, new_number);
}

vector <Bills> Service:: getAllBills(){
    return b.getAllBills();
}

Product Service:: getWantedProduct(int Id) {
    Product wantedProduct;
    for (int i=0;  i < r.getSize(); i++)
    {
           if (r.getAll()[i].getId() == Id)
               wantedProduct = r.getAll()[i];
    }
    return wantedProduct;
}

int Service:: getChange(int Id, int money){
    Product wanted_product;
    int price;
    int change;

    wanted_product = this->getWantedProduct(Id);
    price = this->getPrice(wanted_product.getId());

    if (money > price)
    {
        change = money - price;
    }
    return change;
}











