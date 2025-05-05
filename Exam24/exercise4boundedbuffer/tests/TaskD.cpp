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
    cout << "Buffer initialized with 7 as upper bound and -1 as default value" << endl;
    BoundedBuffer *arb = new BoundedBuffer(7, -1);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass

    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    
    b->write(7); b->write(3); b->write(2);
    cout << "Wrote 7, 3 and 2 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    
    b->write(4);
    b->write(1);
    cout << "Wrote 4 and 1 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;

    arb->setBound(4);
    cout << "Set the new upper bound of the buffer to 4. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;

    b->write(4);
    b->write(3);
    cout << "Wrote 4 and 3 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;

    arb->setBound(3);
    cout << "Set the new upper bound of the buffer to 3. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
      
    arb->setBound(1);
    cout << "Set the new upper bound of the buffer to 1. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;


    delete b;
    return 0;
}
