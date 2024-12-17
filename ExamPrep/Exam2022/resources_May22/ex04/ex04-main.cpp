#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    SensorBuffer *sb = new SensorBuffer(-1, 5, 10);
    Buffer *b = sb; // Just an alias for 'sb' above, but using the superclass

    cout << "Current faults: " << sb->faults() << endl;
    cout << "Reading from the buffer returns: " << b->read() << endl;

    b->write(7); b->write(9);
    cout << "Wrote 7 and 9.  Current faults: " << sb->faults() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    b->write(3); b->write(10);
    cout << "Wrote 3 and 10.  Current faults: " << sb->faults() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    sb->clear();
    cout << "Buffer cleared.  Current faults: " << sb->faults() << endl;
    cout << "Reading from the buffer now returns: " << b->read() << endl;

    delete sb;
    return 0;
}
