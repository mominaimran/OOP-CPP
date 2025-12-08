#include <iostream>
#include "Where.h"
using namespace std;

int main() {
    Where w, w1, w2, w3;
    w1.reveal();
    w2.reveal();
    w3.reveal();
    w.tester();
    w1=w;
    w1.tester();

    return 0;
}