#ifndef CAR_H
#define CAR_H
#include <iostream>
#include <string>
#include "Engine.h"
#include "Gps.h"
using namespace std;

class Car{
    private:
        string brand;
        int year;
        Engine engine;
        Gps gps;
    public:
        Car(string b="unknown", int y=0, Engine e=Engine(), Gps g=Gps());
        void setCar(string b, int y, Engine e, Gps g);
        void showCar()const;
};

#endif