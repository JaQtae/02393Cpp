#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    AutoReducingBuffer *arb = new AutoReducingBuffer(4, -2);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass

    b->write(42);
    b->read();
    b->occupancy();
    arb->contains(4);

    cout << "It compiles!  Test passed!" << endl;

    return 0;
}
