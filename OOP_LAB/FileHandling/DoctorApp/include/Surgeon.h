#ifndef SURGEON_H
#define SURGEON_H

#include "Doctor.h"
#include <fstream>

class Surgeon : public Doctor {
private:
    int totalSurgeries;

public:
    Surgeon(int i = 0, string n = "unknown", int t = 0);
    void setData();
    void showData();
    void modifyRecord(int searchId);
};

#endif
