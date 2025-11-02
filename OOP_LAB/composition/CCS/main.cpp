#include <iostream>
#include "Car.h"
#include "Engine.h"
#include "Gps.h"
using namespace std;

int main() {
    Engine e1("a21");
    Gps g1("v3.8.2", "Islamabad");
    Car c1;
    c1.setCar("BMW", 2020, e1, g1);
    c1.showCar();

    return 0;
}