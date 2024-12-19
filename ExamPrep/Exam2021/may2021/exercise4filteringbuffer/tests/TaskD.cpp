#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    Buffer *b = new FilteringBuffer(-999);

    for (unsigned int i = 0; i < 5; i++) {
        b->write(i * 10);
    }
    cout << "Current buffer occupancy: " << b->occupancy() << endl;

    for (unsigned int i = 0; i < 3; i++) {
      cout << "Reading from the buffer returns: " << b->read() << endl;
    }
    cout << "Current buffer occupancy: " << b->occupancy() << endl;

    b->reset();
    cout << "Buffer occupancy after reset: " << b->occupancy() << endl;

    for (unsigned int i = 0; i < 8; i++) {
        b->write(i * 10);
    }
    cout << "Current buffer occupancy: " << b->occupancy() << endl;
    for (unsigned int i = 0; i < 3; i++) {
      cout << "Reading from the buffer returns: " << b->read() << endl;
    }

    delete b;
    return 0;
}
