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
    cout << "Buffer initialized with capacity 3 and -1 as default value" << endl;
    AutoSummingBuffer *asb = new AutoSummingBuffer(3, -1);
    Buffer *b = asb; // Just an alias for 'cb' above, but using the superclass

    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(7) << " occurrences of 7" << endl;
    cout << "Buffer contains " << asb->occurrences(-1) << " occurrences of -1" << endl;
    
    b->write(7); b->write(3); b->write(2);
    cout << "Wrote 7, 3 and 2 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(7) << " occurrences of 7" << endl;
    cout << "Buffer contains " << asb->occurrences(3) << " occurrences of 3" << endl;
    cout << "Buffer contains " << asb->occurrences(2) << " occurrences of 2" << endl;
    
    b->write(4);
    cout << "Wrote 4 to buffer. ";
    cout << "Buffer contains " << b->occupancy() << " values" << endl;
    cout << "Buffer contains " << asb->occurrences(7) << " occurrences of 7" << endl;
    cout << "Buffer contains " << asb->occurrences(3) << " occurrences of 3" << endl;
    cout << "Buffer contains " << asb->occurrences(2) << " occurrences of 2" << endl;
    cout << "Buffer contains " << asb->occurrences(4) << " occurrences of 4" << endl;
    cout << "Buffer contains " << asb->occurrences(5) << " occurrences of 5" << endl;
    
    b->write(1);
    cout << "Wrote 1 to buffer. ";
    cout << "Buffer now contains " << b->occupancy() << " values" << endl;    
    cout << "Buffer contains " << asb->occurrences(7) << " occurrences of 7" << endl;
    cout << "Buffer contains " << asb->occurrences(3) << " occurrences of 3" << endl;
    cout << "Buffer contains " << asb->occurrences(2) << " occurrences of 2" << endl;
    cout << "Buffer contains " << asb->occurrences(4) << " occurrences of 4" << endl;
    cout << "Buffer contains " << asb->occurrences(5) << " occurrences of 5" << endl;

    delete b;
    return 0;
}
