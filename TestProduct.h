#ifndef LAB_7_TESTPRODUCT_H
#define LAB_7_TESTPRODUCT_H
#include "Product.h"
#include <vector>

class TestProduct {
private:
    vector <Product> products;
    void testGetId();
    void testGetName();
    void testGetPrice();
    void testSetId();
public:
    TestProduct();
    void testAll();
};


#endif //LAB_7_TESTPRODUCT_H
