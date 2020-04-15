#ifndef LAB_7_TESTREPOFILE_H
#define LAB_7_TESTREPOFILE_H
#include "Product.h"
#include "RepoFile.h"


class TestRepoFile {
private:
     RepoFile<Product> r;
     const char* fileNameIn = "TestProductsIn.txt" ;
     const char* fileNameOut = "TestProductsOut.txt";

    void testLoadFromFile();
    void testSaveToFile();

    void testAddProduct();
public:
    TestRepoFile();

    void testAll();

};


#endif //LAB_7_TESTREPOFILE_H
