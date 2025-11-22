#include <iostream>
using namespace std;

template <typename T>
class newClass{
    T d1;
    T d2;
    public:
    void setData(T d1, T d2){
        this->d1 = d1;
        this->d2 = d2;
    }
    T getData1() { return d1; }
    T getData2() { return d2; }
};

int main() {
    // Integer object
    newClass<int> objInt;
    objInt.setData(10, 20);
    cout << "Integer values: " << objInt.getData1() << ", " << objInt.getData2() << endl;
    // String object
    newClass<string> objStr;
    objStr.setData("Momina", "Imran");
    cout << "String values: " << objStr.getData1() << " " << objStr.getData2() << endl;

    return 0;
}