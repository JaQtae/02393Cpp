#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    SensorBuffer *sb = new SensorBuffer(4);
    Buffer *b = sb; // Just an alias for 'sb' above, but using the superclass

    sb->write(42);
    sb->writeCount();
    b->read();
    sb->readAvg();

    cout << "It compiles!  Test passed!" << endl;

    return 0;
}
