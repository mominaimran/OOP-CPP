#include <iostream>
#include "Surgeon.h"
#include <fstream>
using namespace std;

int main() {
    Surgeon s1;
    s1.setData();

    // WRITE FILE
    ofstream outFile("Surgeon.dat", ios::binary);
    if (!outFile) {
        cout << "File not opened for writing!" << endl;
        return 0;
    }

    outFile.write(reinterpret_cast<char*>(&s1), sizeof(s1));
    outFile.close();
    cout << "Data successfully written to file\n";

    // READ FILE
    ifstream inFile("Surgeon.dat", ios::binary);
    if (!inFile) {
        cout << "File not opened for reading!" << endl;
        return 0;
    }

    Surgeon temp;

    // ❗ since only 1 object was written, read only once
    if (inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp))) {
        cout << "\nData read from file:\n";
        temp.showData();
    } else {
        cout << "Could not read record!" << endl;
    }

    inFile.close();
    cout << "Data read successfully\n";

    int id;
    cout << "Enter id of record u want to modify: ";
    cin >> id;
    s1.modifyRecord(id);

    return 0;
}
