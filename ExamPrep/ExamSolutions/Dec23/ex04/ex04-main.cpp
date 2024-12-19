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
    AutoReducingBuffer *arb = new AutoReducingBuffer(3, -1);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass

    b->write(9); b->write(1);
    cout << "Wrote 9 and 1 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains 9? " << boolToString(arb->contains(9)) << endl;
    cout << "Buffer contains 1? " << boolToString(arb->contains(1)) << endl;

    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer still contains 9? " << boolToString(arb->contains(9)) << endl;
    cout << "Buffer still contains 1? " << boolToString(arb->contains(1)) << endl;

    b->write(3); b->write(8); b->write(12); b->write(7);
    cout << "Wrote 3, 8, 12 and 7 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer still contains 1? " << boolToString(arb->contains(1)) << endl;
    cout << "Buffer contains 8? " << boolToString(arb->contains(8)) << endl;
    cout << "Buffer contains 4? " << boolToString(arb->contains(4)) << endl;
    
    b->write(5);
    cout << "Wrote 5 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer still contains 4? " << boolToString(arb->contains(4)) << endl;
    cout << "Buffer contains 6? " << boolToString(arb->contains(6)) << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer still contains 6? " << boolToString(arb->contains(6)) << endl;
    
    delete arb;
    return 0;
}
