#ifndef LAB_7_TESTSERVICE_H
#define LAB_7_TESTSERVICE_H
#include"Product.h"
#include "Bills.h"
#include "Service.h"

class TestService {
private:
    Service s;
    void testAddProduct();
    void testAddBill();
    void testUpdateProductPrice();
    void testGetPrice();
    void testUpdateBillsNumber();
    void testGetWantedProduct();
    void testGetChange();
public:
    TestService();
    void testAll();
};


#endif //LAB_7_TESTSERVICE_H
