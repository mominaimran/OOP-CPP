#include "pointType.h"
#include "lineType.h"
#include <iostream>
using namespace std;

int main() {
    // Points
    pointType p1(1, 2);
    pointType p2(4, 8);
    pointType p3(3, 2);
    pointType p4(3, 5);

    // Distance between points
    cout << "Distance between p1 and p2: " << p1.distance(p2) << endl;
    cout << "Distance between p3 and p4: " << p3.distance(p4) << endl << endl;

    // Lines
    lineType line1(p1, p2);
    lineType line2(p3, p4);

    cout << "Equation of line1: ";
    line1.printEquation(); // slanted

    cout << "Equation of line2: ";
    line2.printEquation(); // vertical

    return 0;
}
