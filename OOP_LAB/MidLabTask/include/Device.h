#ifndef DEVICE_H
#define DEVICE_H
#include <iostream>
#include <string>
using namespace std;

class Device{
    protected:
        string brand;
        string model;
        int batteryLife;
        int price;
    public:
        void setter(string b, string m, int bl, int p);
        string getBrand();
        string getModel();
        int getBatteryLife();
        int getPrice();
        void displayInfo();
};

#endif