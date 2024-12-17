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
    AutoSummingBuffer *asb = new AutoSummingBuffer(3, -1);
    Buffer *b = asb; // Just an alias for 'asb' above, but using the superclass

    b->write(9); b->write(1);
    cout << "Wrote 9 and 1 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(9) << " occurrences of 9" << endl;
    cout << "Buffer contains " << asb->occurrences(1) << " occurrences of 1" << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(9) << " occurrences of 9" << endl;
    cout << "Buffer contains " << asb->occurrences(1) << " occurrences of 1" << endl;
    
    b->write(3); b->write(8); b->write(6); b->write(6);
    cout << "Wrote 3, 8, 6 and 6 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(8) << " occurrences of 8" << endl;
    cout << "Buffer contains " << asb->occurrences(12) << " occurrences of 12" << endl;
    cout << "Buffer contains " << asb->occurrences(6) << " occurrences of 6" << endl;
    
    b->write(5);
    cout << "Wrote 5 to buffer. ";
    cout << "Buffer contains " << asb->occurrences(12) << " occurrences of 12" << endl;
    cout << "Buffer contains " << asb->occurrences(18) << " occurrences of 18" << endl;
    
    cout << "Read " << b->read() << " from buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(18) << " occurrences of 18" << endl;
    
    delete asb;
    return 0;
}
