#include <iostream>
#include "UI.h"


UI:: UI() = default;

UI:: UI(Service& S){
   this->s = S;
}

UI:: ~UI() = default;

void UI:: showMenu() {
    cout << "1. Add a product" << endl;
    cout<< " 2. Show all products"<<endl;
    cout<<"3. Delete a product"<<endl;
    cout << "4. Buy" << endl;
    cout<< "5. Exit"<<endl;
}


void UI:: Menu() {
    int option;
    bool run = true;
    while (run) {
        showMenu();
        cout << "Select option:";
        cin >> option;
        switch (option) {
            case 1:
                this->handleAddProduct();
                break;
            case 2:
                this->handleShowAll();
                break;
            case 3:
                this->handleDeleteProduct();
                break;
            case 4:
                this->buy();
                break;
            case 5:
                run = false;
                break;
            default:
                cout << "Unrecognized command" << endl;
                break;
        }
    }
}

void UI:: handleAddProduct(){
    int Id;
    char a_name[10];
    int price;

    cout<< "Give Id:";
    cin >> Id;
    cout<<"Give name of the product:";
    cin >> a_name;
    cout<< "Give a price:";
    cin >> price;

    char *name = new char[10];
    strcpy(name, a_name);

    s.addProduct(Id, name, price);

}

void UI:: handleDeleteProduct(){
    int Id;
    char a_name[10];
    int price;

    cout<<" Give Id: ";
    cin >> Id;
    cout<<"Give a name: ";
    cin >> a_name;
    cout<<"Give a price: ";
    cin >> price;

    char *name = new char[10];
    strcpy(name, a_name);

    s.deleteProduct(Id, name, price);
}

void UI:: handleShowAll(){
    vector<Product> to_show = s.getAll();
    for (Product i: to_show)
        cout << i << " ";
}

void UI:: buy(){
    int Id;
    cout<<" Select the Id of the product You want to buy: ";
    cin >> Id;
    int price;
    price = s.getPrice(Id);

    if (price == -1)
        {
            cout << "Id invalid"<<endl;
        }
    else
        {
            cout <<"The product costs: " << price << " RON."<<endl;

            int money;
            cout<< "Enter the money: ";
            cin >> money;

            if (money < price )
                {
                    cout << "Not enough money inserted."<<endl;
                    cout << "You still have to enter: "<< price - money<< " RON."<<endl;
                    vector <Product> products = s.getAll();
                    for (int i = 0; i < products.size(); i++)
                        {
                            if (products[i].getPrice() == price)
                                {
                                    s.updateProductPrice(products[i].getId(), price - money);
                                }
                        }
                }
            if(money == price)
                {
                    cout<<"Transaction done"<<endl;
                    cout<<"Enjoy!"<<endl;
                    vector <Product> products = s.getAll();
                    for (int i = 0; i < products.size(); i++)
                    {
                        if (products[i].getPrice() == price)
                        {
                            s.deleteProduct(products[i].getId(), products[i].getName(), products[i].getPrice());
                        }
                    }

                }

           if (money > price)
                {   vector <Bills> bills = s.getAllBills();
                    Bills the_bill;
                    Bills the_bill_1;
                    Bills the_bill_5;
                    int rest = money - price;
                    for (Bills i: bills) {
                        if (i.getValue() == 1)
                            the_bill = i;
                    }
                    if (rest < 5  && the_bill.getNumber() >= rest)
                        {   cout<<"Transaction done!"<<endl;
                            cout<<"Enjoy!"<<endl;
                            cout<<"You'll get a change consisting of: "<<rest/1<< " bills of 1 RON"<<endl;
                            for (Bills i: bills)
                                {
                                    if (i.getValue() == 1)
                                        s.updateBillsNumber(1, i.getNumber()-rest/1);
                                }
                            vector <Product> products = s.getAll();
                            for (int i = 0; i < products.size(); i++)
                            {
                                if (products[i].getPrice() == price)
                                {
                                    s.deleteProduct(products[i].getId(), products[i].getName(), products[i].getPrice());
                                }
                            }

                        }

                    for (Bills i: bills) {
                        if (i.getValue() == 1)
                            the_bill_1 = i;
                        if (i.getValue() == 5)
                            the_bill_5 = i;
                    }
                    if (rest > 5 && rest < 10 && (the_bill_1.getNumber() >= rest || the_bill_5.getNumber() >= rest))
                    {
                        cout<<"Transaction done!"<<endl;
                        cout<<"Enjoy!"<<endl;
                        cout<<"You'll get a change consisting of: "<<1<< " bill of 5 RON and: "<<rest-5<< " bills of 1 RON"<<endl;
                        for (Bills i: bills)
                            {
                                if (i.getValue() == 5)
                                    s.updateBillsNumber(5, i.getNumber()-1);
                                if (i.getValue() == 1)
                                    s.updateBillsNumber(1, i.getNumber() - (rest-5));
                            }
                        vector <Product> products = s.getAll();
                        for (int i = 0; i < products.size(); i++)
                        {
                            if (products[i].getPrice() == price)
                            {
                                s.deleteProduct(products[i].getId(), products[i].getName(), products[i].getPrice());
                            }
                        }
                    }

                }

        }
}

