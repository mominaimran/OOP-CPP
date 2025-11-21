#include "Surgeon.h"

Surgeon::Surgeon(int i, string n, int t) : Doctor(i, n)
{
    totalSurgeries = t;
}

void Surgeon::setData()
{
    Doctor::setData();
    cout << "Enter total surgeries: ";
    cin >> totalSurgeries;
}

void Surgeon::showData()
{
    Doctor::showData();
    cout << "Surgeries performed: " << totalSurgeries << endl;
}

void Surgeon::modifyRecord(int searchId)
{
    fstream file("Surgeon.dat", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "Error opening file!";
        return;
    }
    Surgeon s;
    bool found = false;
    while (file.read(reinterpret_cast<char *>(&s), sizeof(s)))
    {
        if (s.getId() == searchId)
        {
            cout << "Record found. Enter new data: " << endl;
            s.setData();
            file.seekp(-static_cast<int>(sizeof(s)), ios::cur);
            file.write(reinterpret_cast<char *>(&s), sizeof(s));
            cout << "\nUpdated Record:\n";
            s.showData();
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Record not found!";
    }
    file.close();
}