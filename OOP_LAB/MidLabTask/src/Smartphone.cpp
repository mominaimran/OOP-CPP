#include "Smartphone.h"
#include "Colors.h"

void Smartphone::setter(string b, string m, int bl, int p, int c, bool s){
    Device::setter(b, m, bl, p);
    cameraResolution = c;
    supports5G = s;
}

int Smartphone::getCameraResolution(){
    return cameraResolution;
}

bool Smartphone::getSupports5G(){
    return supports5G;
}

void Smartphone::makeCall(){
    cout << "Making a phone call..." << endl;
}

void Smartphone::displaySmartphoneInfo(){
    Device::displayInfo();
    cout << YELLOW << "----- SmartPhone Info -----" << RESET << endl;
    cout << CYAN << "Camera Resolution: " << RESET <<  cameraResolution << " pixels" << endl;
    cout << CYAN << "Supports 5G: " << RESET << supports5G << endl;
    cout  << "-----------------------" << endl;
}