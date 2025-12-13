#include "Admin.h"
#include "Passenger.h"
#include "colorUtils.h"
#include "UIUtils.h"
#include <iostream>
#include <limits>
#include <windows.h>
using namespace std;

int main()
{
    int choice;
    do
    {
        printHeader();
        // Menu options
        cout << "1️⃣  Continue as Admin" << endl;
        cout << "2️⃣  Continue as Passenger" << endl;
        cout << "0️⃣  Exit" << endl;

        cout << BOLD_CYAN << "-> Enter your choice: " << RESET;
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            // Admin block
            Admin admin;
            bool authenticated = false;

            while (!authenticated)
            {
                // Admin Auth Menu
                cout << BOLD_YELLOW << "\n╔════════════════════════════╗\n";
                cout << "║     ADMIN LOGIN/SIGNUP     ║\n";
                cout << "╚════════════════════════════╝\n"
                     << RESET;

                cout << GREEN << "1️⃣  LOGIN (Already have an account)" << RESET << endl;
                cout << GREEN << "2️⃣  SIGNUP (Don't have an account)" << RESET << endl;

                int adminChoice;
                cout << BOLD_CYAN << "-> Enter your choice: " << RESET;
                cin >> adminChoice;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (adminChoice == 1)
                {
                    if (admin.login())
                        authenticated = true;
                }
                else if (adminChoice == 2)
                {
                    if (admin.signup())
                        authenticated = true;
                }
                else
                {
                    cout << RED << "❌ Invalid choice!\n"
                         << RESET;
                    Beep(800, 100);
                }
            }
            admin.showMenu();
            break;
        }
        case 2:
        {
            Passenger passenger;
            passenger.showMenu();
            break;
        }
        case 0:
            printSystemFooter();
            cout << BOLD_YELLOW << "👋 Exiting Program...\n"
                 << RESET;
            Beep(700, 150);
            break;
        default:
            cout << RED << "❌ Invalid choice! Try again.\n"
                 << RESET;
        }
    } while (choice != 0);

    return 0;
}

//** ️Key Features to Highlight
// Role-based system: Admin vs Passenger
// Clean console UI using colors (colorUtils.h)
// Safe input handling with cin.ignore()
// Modular code: Admin and Passenger features are in separate classes
// Loop until exit: do-while keeps the program running until user chooses to exit