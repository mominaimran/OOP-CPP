#include <iostream>
using namespace std;
template <typename T>
void reverseArray(T arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main() {
    int arrInt[] = {1, 2, 3, 4, 5};
    int size = 5;
    cout << "Original array: ";
    printArray(arrInt, size);
    reverseArray(arrInt, size);
    cout << "Reversed array: ";
    printArray(arrInt, size);
    return 0;
}
