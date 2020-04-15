#ifndef LAB_7_TESTREPOFILEBILLS_H
#define LAB_7_TESTREPOFILEBILLS_H
#include "Bills.h"
#include "RepoFileBills.h"


class TestRepoFileBills {
private:
    RepoFileBills<Bills> b;
    const char* fileNameIn = "TestBillsIn.txt" ;
    const char* fileNameOut = "TestBillsOut.txt";

    void testLoadFromFile();
    void testSaveToFile();

    void testAddBill();
public:
    TestRepoFileBills();

    void testAll();

};


#endif //LAB_7_TESTREPOFILEBILLS_H
