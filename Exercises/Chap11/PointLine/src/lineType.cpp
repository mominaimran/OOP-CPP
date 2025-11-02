#include "lineType.h"

// Constructor
lineType::lineType(pointType a, pointType b) : p1(a), p2(b) {}

// Check if vertical line
bool lineType::isVertical() const {
    return (p1.getX() == p2.getX());
}

// Check if horizontal line
bool lineType::isHorizontal() const {
    return (p1.getY() == p2.getY());
}

// Check if slanted
bool lineType::isSlanted() const {
    return (!isVertical() && !isHorizontal());
}

// Slope calculation
double lineType::slope() const {
    if (isVertical()) {
        throw runtime_error("Slope undefined for vertical line.");
    }
    return (p2.getY() - p1.getY()) / (p2.getX() - p1.getX());
}

// Print equation
void lineType::printEquation() const {
    if (isVertical()) {
        cout << "x = " << p1.getX() << endl;
    } else if (isHorizontal()) {
        cout << "y = " << p1.getY() << endl;
    } else {
        double m = slope();
        double b = p1.getY() - m * p1.getX();
        cout << "y = " << m << "x + " << b << endl;
    }
}
