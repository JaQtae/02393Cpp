#include <iostream>
#include "../ex04-library.h"
using namespace std;

string boolToString(bool v){
    if(v) {
        return "true";
    } else {
        return "false";
    }
}


int main() {
    cout << "Buffer initialized with capacity 3 and -1 as default value" << endl;
    AutoReducingBuffer *arb = new AutoReducingBuffer(3, -1);
    Buffer *b = arb; // Just an alias for 'cb' above, but using the superclass

    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains 7? " << boolToString(arb->contains(7)) << endl;
    cout << "Buffer contains -1? " << boolToString(arb->contains(-1)) << endl;

    b->write(7); b->write(3); b->write(2);
    cout << "Wrote 7, 3 and 2 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains 7? " << boolToString(arb->contains(7)) << endl;
    cout << "Buffer contains 3? " << boolToString(arb->contains(3)) << endl;
    cout << "Buffer contains 2? " << boolToString(arb->contains(2)) << endl;
    
    b->write(4);
    cout << "Wrote 4 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains 7? " << boolToString(arb->contains(7)) << endl;
    cout << "Buffer contains 3? " << boolToString(arb->contains(3)) << endl;
    cout << "Buffer contains 2? " << boolToString(arb->contains(2)) << endl;
    cout << "Buffer contains 4? " << boolToString(arb->contains(4)) << endl;
    cout << "Buffer contains 5? " << boolToString(arb->contains(5)) << endl;

    b->write(1);
    cout << "Wrote 1 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;    
    cout << "Buffer contains 7? " << boolToString(arb->contains(7)) << endl;
    cout << "Buffer contains 3? " << boolToString(arb->contains(3)) << endl;
    cout << "Buffer contains 2? " << boolToString(arb->contains(2)) << endl;
    cout << "Buffer contains 4? " << boolToString(arb->contains(4)) << endl;
    cout << "Buffer contains 5? " << boolToString(arb->contains(5)) << endl;

    delete b;
    return 0;
}
