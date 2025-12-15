// Exception handling allows safe execution by catching errors at runtime instead of crashing the program.
#include <iostream>
using namespace std;

int main() {
    // try{
    //     int x=10, y=0;
    //     if(y==0) throw y;
    //     cout << x/y;
    // }catch(int e){
    //     cout << "Error: Division by " << e << endl; 
    // }
    
    int x=20, y=0;
    if(y==0){
        cout << "Divison by 0 not allowed";
    }else{
        cout << x/y << endl;
    }

    return 0;
}