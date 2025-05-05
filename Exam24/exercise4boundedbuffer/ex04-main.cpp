#include <iostream>
#include "ex04-library.h"
using namespace std;

string boolToString(bool v){
    if(v) {
        return "true";
    } else {
        return "false";
    }
}

int main() {
    BoundedBuffer *arb = new BoundedBuffer(5, -1);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass
    cout << "Buffer initialized with 5 as upper bound and -1 as default value" << endl;

    b->write(9); b->write(1);
    cout << "Wrote 9 and 1 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;

    b->write(3); b->write(8); b->write(2); b->write(4);
    cout << "Wrote 3, 8, 2 and 4 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    arb->setBound(3);
    cout << "Set the new upper bound of the buffer to 3. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    
    delete arb;
    return 0;
}
