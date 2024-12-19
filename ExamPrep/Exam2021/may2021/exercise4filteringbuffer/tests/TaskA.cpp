#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    Buffer *b = new FilteringBuffer(-999);

    b->write(42);
    b->write(42);
    unsigned int test1 = b->occupancy();
    int test2 = b->read();

    cout << "It compiles! Test passed!" << endl;

    delete b;
    return 0;
}
