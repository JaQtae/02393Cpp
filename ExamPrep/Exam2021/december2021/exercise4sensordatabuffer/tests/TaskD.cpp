#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    SensorBuffer *sb = new SensorBuffer(6);
    Buffer *b = sb; // Just an alias for 'sb' above, but using the superclass

    cout << "The buffer average is: " << sb->readAvg() << endl;

    b->write(2); b->write(20);
    cout << "The buffer average is now: " << sb->readAvg() << endl;

    b->write(7); b->write(3);
    cout << "The buffer average is now: " << sb->readAvg() << endl;

    b->write(1); b->write(3);
    cout << "The buffer average is now: " << sb->readAvg() << endl;

    b->write(4); b->write(0);
    cout << "The buffer average is now: " << sb->readAvg() << endl;

    delete sb;
    return 0;
}
