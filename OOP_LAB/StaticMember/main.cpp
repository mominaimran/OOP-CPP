#include "Counter.h"

int main() {
    Counter c1, c2, c3; // 3 objects created

    c1.show();
    c2.show();
    c3.show();

    // calling static function (no object needed)
    Counter::showCount();

    return 0;
}
