#include <iostream>
#include <exception>
using namespace std;

int main() {
    try{
        throw out_of_range("Index exceeded array size!");
    }
    catch(out_of_range &e){
        cout << "out of range: " << e.what();
    }
    catch(const exception &e){
        cout << "General Exception: " << e.what();
    }
    catch(...){
        cout << "unknown error";
    }

    return 0;
}

//🎁 Built-in Exceptions