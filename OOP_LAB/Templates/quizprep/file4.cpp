#include <iostream>
using namespace std;

template <typename T, int size>
class Array{
    T arr[size];
    public:
    void fillArray(){
        for(int i=0; i<size; i++){
            arr[i] = i+1;
        }
    }
    void printArray(){
        for(int i=0; i<size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int, 10> arr1;
    arr1.fillArray();
    arr1.printArray();

    Array<char, 4> arr3;    
    arr3.fillArray();       
    arr3.printArray();


    return 0;
}