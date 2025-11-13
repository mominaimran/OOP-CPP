#include "Circle.h"
#include "ColorUtils.h"
#include <iostream>
using namespace std;

void Circle::draw() {
    string code = getColorCode(color);
    cout << "\nColor: " << color << endl;
    cout << code;
    cout << "   @@@   \n";
    cout << " @@@@@@@ \n";
    cout << "@@@@@@@@@\n";
    cout << " @@@@@@@ \n";
    cout << "   @@@   \n";
    cout << "\033[0m"; // reset
    cout << "A " << color << " Circle drawn successfully!\n";
}
