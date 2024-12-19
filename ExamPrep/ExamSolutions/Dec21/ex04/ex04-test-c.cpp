#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    SensorBuffer *sb = new SensorBuffer(4);
    Buffer *b = sb; // Just an alias for 'sb' above, but using the superclass

    cout << "Reading from the buffer returns: " << b->read() << endl;

    b->write(1); b->write(42);
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    b->write(4); b->write(5); b->write(-100);
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    b->write(5);
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    delete sb;
    return 0;
}
