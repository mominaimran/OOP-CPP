#include "Surgeon.h"
#include "ColorUtils.h"

int main() {
    int choice;
    do {
        cout << RED << "\n========== Surgeon Management ==========\n" << RESET;
        cout << "1. Add Surgeon\n";
        cout << YELLOW << "2. Display All Surgeons\n" << RESET;
        cout << "3. Modify Surgeon Record\n";
        cout << YELLOW << "4. Copy File\n" << RESET;
        cout << "5. Exit\n";

        cout << GREEN << "Enter choice: " << RESET;
        cin >> choice;

        switch (choice) {
        case 1: addSurgeon(); break;
        case 2: displayAll(); break;
        case 3: modifyRecord(); break;
        case 4: copyFile(); break;
        case 5: cout << YELLOW << "\nExiting...\n" << RESET; break;
        default: cout << RED << "\nInvalid choice!\n" << RESET;
        }
    } while (choice != 5);

    return 0;
}
