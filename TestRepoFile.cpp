#include "TestRepoFile.h"
#include <cassert>
#include <cstring>

TestRepoFile::TestRepoFile() = default;

void TestRepoFile:: testAll(){
    this->testLoadFromFile();
    this->testSaveToFile();
    this->testAddProduct();
}


void TestRepoFile::testLoadFromFile() {
    this->r.setFileNameIn(this->fileNameIn);
    this->r.loadFromFile();
    assert(this->r.getSize() == 4);

}

void TestRepoFile::testSaveToFile() {
    this->r.setFileNameIn(this->fileNameIn);
    this->r.setFileNameOut(this->fileNameOut);
    this->r.loadFromFile();

    int initialLen = this->r.getSize();

    char a_name5 [100] = "joe";
    char *name5 = new char[strlen(a_name5)+1];
    strcpy(name5, a_name5);

    Product p5(5, name5, 5);
    this->r.addProduct(p5);

    this->r.saveToFile();

    assert(this->r.getSize() == initialLen + 1);
}

void TestRepoFile:: testAddProduct(){
    this->r.setFileNameIn(this->fileNameIn);
    this->r.setFileNameOut(this->fileNameOut);
    this->r.loadFromFile();

    int initialLen = this->r.getSize();

    char a_name6 [100] = "7days";
    char *name6 = new char[strlen(a_name6)+1];
    strcpy(name6, a_name6);

    Product p6(6, name6, 6);
    this->r.addProduct(p6);

    this->r.saveToFile();

    assert(this->r.getSize() == initialLen + 1);
}




























