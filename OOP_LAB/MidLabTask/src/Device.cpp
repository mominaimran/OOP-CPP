#include "Device.h"
#include "Colors.h"

void Device::setter(string b, string m, int bl, int p){
    brand = b;
    model = m;
    batteryLife = bl;
    price = p;
}

string Device::getBrand(){
    return brand;
}

string Device::getModel(){
    return model;
}

int Device::getBatteryLife(){
    return batteryLife;
}

int Device::getPrice(){
    return price;
}

void Device::displayInfo(){
    cout << YELLOW << "----- Device Info -----" << RESET << endl;
    cout << CYAN << "Brand: " << RESET <<  brand << endl;
    cout << CYAN << "Model: " << RESET <<  model << endl;
    cout << CYAN << "Battery Life: " << RESET <<  batteryLife << " hr" << endl;
    cout << CYAN << "Price: " << RESET << price << " USD" << endl;
}