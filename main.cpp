#include "UI.h"
#include "RepoFile.h"
#include "RepoFileBills.h"
#include "Service.h"
#include "TestProduct.h"
#include "TestProduct.cpp"
#include "TestRepoFile.h"
#include "TestRepoFile.cpp"
#include "TestRepoFileBills.h"
#include "TestRepoFileBills.cpp"
#include "TestService.h"
#include "TestService.cpp"

using namespace std;

int main() {

    TestProduct testProduct;
    testProduct.testAll();

   TestRepoFile testRepoFile;
   testRepoFile.testAll();

   TestRepoFileBills testRepoFileBills;
   testRepoFileBills.testAll();

   TestService testService;
   testService.testAll();

    RepoFile<Product> r("ProductsIn.txt", "ProductsOut.txt");
    RepoFileBills <Bills> b("BillsIn.txt", "BillsOut.txt");
    Service s(r, b);
    UI ui(s);
    ui.Menu();

    return 0;
}
