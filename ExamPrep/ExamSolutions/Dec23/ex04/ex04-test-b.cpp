#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    cout << "Buffer initialized with capacity 5" << endl;
    AutoReducingBuffer *arb = new AutoReducingBuffer(5, -2);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass

    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    
    b->write(4); b->write(2); b->write(3);
    cout << "Wrote 4, 2 and 3 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    
    b->write(1); b->write(6);
    cout << "Wrote 1 and 6 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    b->write(7); b->write(5);
    cout << "Wrote 7 and 5 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    delete arb;
    return 0;
}
