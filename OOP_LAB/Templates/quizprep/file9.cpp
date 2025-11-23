#include <iostream>
using namespace std;

// Template function with non-type parameter
template <typename T, int size>
void sumElems(T arr[size]) {
    T sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }
    cout << "Sum of elements: " << sum << endl;
}

int main() {
    int arr1[5] = {1, 2, 3, 4, 5};
    sumElems<int, 5>(arr1);

    float arr2[4] = {1.5, 2.5, 3.0, 4.0};
    sumElems<float, 4>(arr2);

    return 0;
}
