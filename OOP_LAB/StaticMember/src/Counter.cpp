
#include "Counter.h"

// static member variable initialization
int Counter::count = 0;

Counter::Counter() {
    count++;
    id = count;
}

void Counter::show() const {
    cout << "Object number: " << id << endl;
}

void Counter::showCount() {
    cout << "Total objects created: " << count << endl;
}
