#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

int main() {
// 1) invalid_argument
try {
    int age = -5;
    if (age < 0)
        throw invalid_argument("Age cannot be negative!");
}
catch(const invalid_argument &e) {
    cout << "[invalid_argument] " << e.what() << endl;
}
// 2) out_of_range (vector index error)
try {
    vector<int> nums = {10, 20, 30};
    cout << nums.at(5);   // this will throw out_of_range
}
catch(const out_of_range &e) {
    cout << "[out_of_range] " << e.what() << endl;
}
// 3) length_error
try {
    vector<int> v;
    v.reserve(v.max_size() + 1);   
}
catch(const length_error &e) {
    cout << "[length_error] " << e.what() << endl;
}
// 4) overflow_error
try {
    throw overflow_error("Mathematical overflow!");
}
catch(const overflow_error &e) {
    cout << "[overflow_error] " << e.what() << endl;
}
// 5) underflow_error
try {
    throw underflow_error("Mathematical underflow!");
}
catch(const underflow_error &e) {
    cout << "[underflow_error] " << e.what() << endl;
}
// 6) runtime_error
try {
    throw runtime_error("Generic runtime error occurred!");
}
catch(const runtime_error &e) {
    cout << "[runtime_error] " << e.what() << endl;
}
// 7) bad_alloc (Memory allocation failure)
try {
    int* big = new int[9999999999999];
    delete[] big;
}
catch(const bad_alloc &e) {
    cout << "[bad_alloc] " << e.what() << endl;
}

return 0;
}
