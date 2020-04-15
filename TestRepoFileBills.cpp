#include "TestRepoFileBills.h"
#include <cassert>

TestRepoFileBills::TestRepoFileBills() = default;

void TestRepoFileBills:: testAll(){
    this->testLoadFromFile();
    this->testSaveToFile();
    this->testAddBill();
}

void TestRepoFileBills::testLoadFromFile() {
    this->b.setFileNameIn(this->fileNameIn);
    this->b.loadFromFile();

    assert(this->b.getSizeBills() == 3);
}

void TestRepoFileBills:: testSaveToFile(){
    this->b.setFileNameIn(fileNameIn);
    this->b.setFileNameOut(fileNameOut);
    this->b.loadFromFile();

    int initialLen = b.getSizeBills();

    b.addBill(Bills(50, 1));
    b.saveToFile();

    assert(b.getSizeBills() == initialLen +1);

}

void TestRepoFileBills::testAddBill() {
    this->b.setFileNameIn(fileNameIn);
    this->b.setFileNameOut(fileNameOut);
    this->b.loadFromFile();

    int initialLen = b.getSizeBills();

    b.addBill(Bills(100, 2));
    b.saveToFile();

    assert(b.getSizeBills() == initialLen +1);
}