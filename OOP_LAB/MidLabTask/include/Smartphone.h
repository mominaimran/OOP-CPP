#ifndef SMARTPHONE_H
#define SMARTPHONE_H
#include "Device.h"
using namespace std;

class Smartphone : public Device{
    protected:
        int cameraResolution;
        bool supports5G;
    public:
        void setter(string b, string m, int bl, int p, int c, bool s);
        void makeCall();
        int getCameraResolution();
        bool getSupports5G();
        void displaySmartphoneInfo();
};

#endif