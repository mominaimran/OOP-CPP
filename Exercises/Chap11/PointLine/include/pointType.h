#ifndef POINTTYPE_H
#define POINTTYPE_H

#include <cmath>
using namespace std;

class pointType {
private:
    double x;
    double y;

public:
    // Constructors
    pointType(double xVal = 0, double yVal = 0);

    // Setters
    void setX(double xVal);
    void setY(double yVal);

    // Getters
    double getX() const;
    double getY() const;

    // Distance to another point
    double distance(const pointType& p) const;
};

#endif
