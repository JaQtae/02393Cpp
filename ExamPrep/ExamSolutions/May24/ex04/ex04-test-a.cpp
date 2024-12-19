#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    AutoSummingBuffer *asb = new AutoSummingBuffer(4, -2);
    Buffer *b = asb; // Just an alias for 'asb' above, but using the superclass

    b->write(42);
    b->read();
    b->occupancy();
    asb->occurrences(4);

    cout << "It compiles!  Test passed!" << endl;

    return 0;
}
