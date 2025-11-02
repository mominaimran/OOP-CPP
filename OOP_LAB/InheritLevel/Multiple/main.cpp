#include <iostream>
#include "Manager.h"
using namespace std;

int main() {
    Manager m(111, 200000, 5889, 4, "IT"), m1;
    m.showData();

    m1.getData();
    m1.showData();
    
    return 0;
}
