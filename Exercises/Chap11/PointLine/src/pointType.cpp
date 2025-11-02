#include "pointType.h"

// Constructors
pointType::pointType(double xVal, double yVal) {
    x = xVal;
    y = yVal;
}

// Setters
void pointType::setX(double xVal) { x = xVal; }
void pointType::setY(double yVal) { y = yVal; }

// Getters
double pointType::getX() const { return x; }
double pointType::getY() const { return y; }

// Distance function
double pointType::distance(const pointType& p) const {
    double dx = x - p.getX();
    double dy = y - p.getY();
    return sqrt(dx * dx + dy * dy);
}
