#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    CountingBuffer *cb = new CountingBuffer(-1);
    Buffer *b = cb; // Just an alias for 'cb' above, but using the superclass

    cb->write(42);
    cb->mostFrequent();
    cb->frequency(4);
    b->clear();

    cout << "It compiles!  Test passed!" << endl;

    return 0;
}
