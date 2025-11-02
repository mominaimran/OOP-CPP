#ifndef LINETYPE_H
#define LINETYPE_H

#include "pointType.h"
#include <iostream>
using namespace std;

class lineType {
private:
    pointType p1;
    pointType p2;

public:
    // Constructor
    lineType(pointType a = pointType(), pointType b = pointType());

    // Line properties
    bool isVertical() const;
    bool isHorizontal() const;
    bool isSlanted() const;
    double slope() const;
    void printEquation() const;
};

#endif
