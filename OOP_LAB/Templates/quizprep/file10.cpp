#include <iostream>
using namespace std;

// Template class with non-type argument
template <typename T, int size>
class Array {
    T arr[size];

public:
    // Fill array with values 1, 2, ..., size
    void fillArray() {
        for (int i = 0; i < size; i++) {
            arr[i] = i + 1;
        }
    }

    // Sum array elements
    T sumArray() {
        T sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }

    // Display array elements
    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Array<int, 5> arr1;  // Array of 5 integers
    arr1.fillArray();
    arr1.printArray();
    cout << "Sum of array: " << arr1.sumArray() << endl;

    Array<float, 4> arr2; // Array of 4 floats
    arr2.fillArray();
    arr2.printArray();
    cout << "Sum of array: " << arr2.sumArray() << endl;

    return 0;
}
