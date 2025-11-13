#include <iostream>
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Cube.h"
#include "Tetrahedron.h"
#include "ColorUtils.h"
using namespace std;

int main() {
    int type, shapeChoice;
    string color;

    cout << CYAN << "Select Shape Type:\n" << RESET;
    cout << "1. Two Dimensional\n";
    cout << "2. Three Dimensional\n";
    cout << YELLOW << "Enter your choice: " << RESET;
    cin >> type;

    if (type == 1) {
        cout << CYAN << "\nSelect a 2D Shape:\n" << RESET;
        cout << "1. Circle\n2. Square\n3. Triangle\n";
        cout << YELLOW << "Enter your choice: " <<  RESET;
        cin >> shapeChoice;

        cout << MAGENTA << "Enter color: " << RESET;
        cin >> color;

        if (shapeChoice == 1) {
            Circle c;
            c.setColor(color);
            c.showType();
            c.draw();
        }
        else if (shapeChoice == 2) {
            Square s;
            s.setColor(color);
            s.showType();
            s.draw();
        }
        else if (shapeChoice == 3) {
            Triangle t;
            t.setColor(color);
            t.showType();
            t.draw();
        }
        else cout << RED << "Invalid Shape!\n" RESET;
    }
    else if (type == 2) {
        cout << "\nSelect a 3D Shape:\n";
        cout << "1. Sphere\n2. Cube\n3. Tetrahedron\n";
        cout << YELLOW << "Enter your choice: " RESET;
        cin >> shapeChoice;

        cout << "Enter color: ";
        cin >> color;

        if (shapeChoice == 1) {
            Sphere s;
            s.setColor(color);
            s.showType();
            s.draw();
        }
        else if (shapeChoice == 2) {
            Cube c;
            c.setColor(color);
            c.showType();
            c.draw();
        }
        else if (shapeChoice == 3) {
            Tetrahedron t;
            t.setColor(color);
            t.showType();
            t.draw();
        }
        else cout << "Invalid Shape!\n";
    }
    else {
        cout << "Invalid Type!\n";
    }

    return 0;
}
