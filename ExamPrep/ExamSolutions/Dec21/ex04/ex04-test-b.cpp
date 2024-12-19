#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    SensorBuffer *sb = new SensorBuffer(4);
    Buffer *b = sb; // Just an alias for 'sb' above, but using the superclass

    cout << "Current write count: " << sb->writeCount() << endl;

    b->write(1); b->write(2); b->write(3); b->write(4);
    cout << "Current write count: " << sb->writeCount() << endl;

    b->write(5); b->write(6); b->write(-33);
    cout << "Current write count: " << sb->writeCount() << endl;

    delete sb;
    return 0;
}
