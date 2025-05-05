#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    BoundedBuffer *arb = new BoundedBuffer(8, -2);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass
    cout << "Buffer initialized with 8 as upper bound and -2 as default value" << endl;

    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    b->write(5); b->write(7);
    cout << "Wrote 5 and 7 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    b->write(8); b->write(2); b->write(6);
    cout << "Wrote 8, 2 and 6 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    b->write(4); b->write(4); b->write(1); b->write(3); b->write(6);
    cout << "Wrote 4, 4, 1, 3 and 6 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    delete arb;
    return 0;
}
