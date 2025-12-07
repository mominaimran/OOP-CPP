#include <iostream>
#include <fstream>
using namespace std;

class Student{
    private:
        int id;
        char name[20];
        float CGPA;
    public:
        int getId(){
            return id;
        }
        void input(){
            cout << "Enter Id: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            cout << "Enter CGPA: ";
            cin >> CGPA;
        }
        void display(){
            cout << "ID: " << id << ", Name: " << name << ", CGPA: " << CGPA << endl;
        }
};

//Add Student
void addStudent(){
    Student s;
    s.input();

    ofstream outFile("Student.dat", ios::binary | ios::app);
    outFile.write(reinterpret_cast<char*>(&s), sizeof(s));
    outFile.close();

    cout << "Student added successfully!\n";
}
//Display All
void displayAllStudents(){
    Student temp;
    ifstream inFile("Student.dat", ios::binary);
    while(inFile.read(reinterpret_cast<char*>(&temp), sizeof(temp))){
        temp.display();
    }
    inFile.close();
    cout << "Students read successfully!\n";
}

//Update student by Id
void updateStudent(int Id){
    fstream file("Student.dat", ios::in | ios::out | ios::binary);
    Student s;

    bool found = false;
    while(file.read(reinterpret_cast<char*>(&s), sizeof(s))){
       if(s.getId()==Id){
            cout << "Current details:\n";
            s.display();
            cout << "Enter new details:\n";
            s.input();
            file.seekp(-static_cast<long>(sizeof(s)), ios::cur);
            file.write(reinterpret_cast<char*>(&s), sizeof(s));
            found = true;
            cout << "Student updated!\n";
            break;
       }
    }
    if(!found) cout << "Student with ID " << Id << " not found.\n";
    file.close();
}

//Delete student by Id
void deleteStudent(int Id){
    ifstream fin("Student.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);
    Student s;

    bool found = false;
    while(fin.read(reinterpret_cast<char*>(&s), sizeof(s))){
        if(s.getId()!=Id)
            fout.write(reinterpret_cast<char*>(&s), sizeof(s));
        else
        found = true;
    }
    fin.close();
    fout.close();

    remove("Student.dat");
    rename("temp.dat", "Student.dat");

    if(found) cout << "Student deleted!\n";
    else cout << "Student with ID " << Id << " not found.\n";
}

int main() {
    int choice, id;

    do {
        cout << "\n--- Student Binary File CRUD ---\n";
        cout << "1. Add Student\n2. Display All\n3. Update Student\n4. Delete Student\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: addStudent(); break;
            case 2: displayAllStudents(); break;
            case 3: 
                cout << "Enter ID to update: "; cin >> id;
                updateStudent(id); 
                break;
            case 4: 
                cout << "Enter ID to delete: "; cin >> id;
                deleteStudent(id); 
                break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while(choice != 5);
    return 0;
}