#include <iostream>
#include "Colors.h"
#include "Smartphone.h"
using namespace std;

int main() {
    Smartphone s1;
    s1.setter("Apple", "i17", 18, 500, 30, true);
    s1.displaySmartphoneInfo();
    s1.makeCall();

    return 0;
}