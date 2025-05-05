#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    BoundedBuffer *arb = new BoundedBuffer(5, -2);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass
    cout << "Buffer initialized with 5 as upper bound and -2 as default value" << endl;

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
