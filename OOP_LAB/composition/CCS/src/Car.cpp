#include "Car.h"

Car::Car(string b, int y, Engine e, Gps g):engine(e), gps(g){
    brand=b;
    year=y;
}

void Car::setCar(string b, int y, Engine e, Gps g){
    brand=b;
    year=y;
    engine=e;
    gps = g;
}

void Car::showCar()const{
    cout << "Car brand: " << brand << ", year: " << year << endl;
    engine.showEngine();
    gps.showGps();
}