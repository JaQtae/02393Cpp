#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    SensorBuffer *sb = new SensorBuffer(4);
    Buffer *b = sb; // Just an alias for 'sb' above, but using the superclass

    cout << "Current write count: " << sb->writeCount() << endl;
    cout << "Reading from the buffer returns: " << b->read() << endl;

    b->write(1); b->write(2);
    cout << "Current write count: " << sb->writeCount() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    b->write(4); b->write(5);
    cout << "Current write count: " << sb->writeCount() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;
    cout << "The buffer average is now: " << sb->readAvg() << endl;

    b->write(5);
    cout << "Current write count: " << sb->writeCount() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;
    cout << "The buffer average is now: " << sb->readAvg() << endl;

    delete sb;
    return 0;
}
