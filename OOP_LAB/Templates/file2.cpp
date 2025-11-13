#include <iostream>
#include <cctype>
using namespace std;

template <typename T>
void toUpperCase(T arr[]){
    for(int i=0; arr[i]!= '\0'; i++){
        arr[i] = toupper(arr[i]); 
    }
    cout << "UpperCase: " << arr << endl;
}

int main() {
    char array[100];
    cout << "Enter character array: ";
    cin.getline(array, 100);
    toUpperCase(array);

    return 0;
}