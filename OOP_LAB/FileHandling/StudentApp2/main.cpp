#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

class Student
{
private:
    string name, reg;
    float CGPA;
    int ID;

public:
    Student()
    {
        ID = 0;
        CGPA = 0;
    }

    void setProfile(int id)
    {
        ID = id; // Assign the ID passed from main
        cin.ignore(); // clear buffer

        cout << "\nEnter student name: ";
        getline(cin, name);

        cout << "Enter registration number: ";
        getline(cin, reg);

        cout << "Enter CGPA: ";
        cin >> CGPA;
    }

    void displayProfile() const
    {
        cout << setw(5) << ID
             << setw(20) << name
             << setw(10) << reg
             << setw(5) << CGPA << endl;
    }

    int getID() const { return ID; }
    void setCGPA(float cg) { CGPA = cg; }

    friend void ModifyData(int id);
};

// Modify student CGPA in file
void ModifyData(int id)
{
    fstream file("student.txt", ios::binary | ios::in | ios::out);
    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }

    Student s;
    while (file.read(reinterpret_cast<char*>(&s), sizeof(s)))
    {
        if (s.ID == id)
        {
            cout << "\nEnter new CGPA for student ID " << id << ": ";
            float newCGPA;
            cin >> newCGPA;
            s.setCGPA(newCGPA);

            file.seekp(-static_cast<long>(sizeof(s)), ios::cur);
            file.write(reinterpret_cast<char*>(&s), sizeof(s));
            cout << "\nRecord updated successfully.\n";
            file.close();
            return;
        }
    }

    cout << "Student with ID " << id << " not found.\n";
    file.close();
}

int main()
{
    Student s;
    ofstream outFile("student.txt", ios::binary | ios::app);
    if (!outFile)
    {
        cout << "Cannot open file for writing.\n";
        return 1;
    }

    int resp = 1;
    int nextID = 1;

    // Determine next ID based on existing records
    ifstream inFile("student.txt", ios::binary);
    Student temp;
    while (inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp)))
        nextID = temp.getID() + 1;
    inFile.close();

    // Input student data
    while (resp == 1)
    {
        s.setProfile(nextID++);
        outFile.write(reinterpret_cast<char*>(&s), sizeof(s));

        cout << "\nDo you want to enter another student's data? (1 = Yes, 0 = No): ";
        cin >> resp;
    }
    outFile.close();

    // Display all students
    ifstream inFileDisplay("student.txt", ios::binary);
    if (!inFileDisplay)
    {
        cout << "Cannot open file for reading.\n";
        return 1;
    }

    cout << endl
         << setw(5) << "ID"
         << setw(20) << "Student Name"
         << setw(10) << "Reg#"
         << setw(5) << "GPA" << endl;

    while (inFileDisplay.read(reinterpret_cast<char*>(&s), sizeof(s)))
    {
        s.displayProfile();
    }
    inFileDisplay.close();

    // Modify a student's CGPA
    int modifyID;
    cout << "\nEnter the ID of the student to modify CGPA: ";
    cin >> modifyID;
    ModifyData(modifyID);

    // Display updated records
    ifstream inFileFinal("student.txt", ios::binary);
    cout << "\nUpdated Student Records:\n";
    cout << setw(5) << "ID"
         << setw(20) << "Student Name"
         << setw(10) << "Reg#"
         << setw(5) << "GPA" << endl;

    while (inFileFinal.read(reinterpret_cast<char*>(&s), sizeof(s)))
    {
        s.displayProfile();
    }
    inFileFinal.close();

    cout << "\nFile read completely.\n";
    
    return 0;
}
