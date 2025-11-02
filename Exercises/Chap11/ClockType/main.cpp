#include "extClockType.h"
#include "colors.h"
#include <iostream>
using namespace std;

int main() {
    extClockType myClock(10, 45, 30, "PST");
    
    cout << BLUE << "==============================" << RESET << endl;
    cout << YELLOW << "Current Time Zone: " << RESET 
         << GREEN << "PST" << RESET << endl;
    
    cout << CYAN << "Current Time: " << RESET;
    myClock.printTime();

    cout << "\n" << BLUE << "------------------------------" << RESET << endl;
    cout << MAGENTA << "Changing time zone..." << RESET << endl;

    myClock.setTimeZone("EST");

    cout << YELLOW << "Updated Time Zone: " << RESET 
         << GREEN << "EST" << RESET << endl;

    cout << CYAN << "Updated Time: " << RESET;
    myClock.printTime();

    cout << "\n" << BLUE << "==============================" << RESET << endl;

    return 0;
}

