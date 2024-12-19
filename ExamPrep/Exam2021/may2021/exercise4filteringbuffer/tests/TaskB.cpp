#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    Buffer *b = new FilteringBuffer(-999);

    cout << "Current buffer occupancy: " << b->occupancy() << endl;
    
    for (unsigned int i = 0; i < 7; i++) {
        b->write(i * 10);
    }
    cout << "Current buffer occupancy: " << b->occupancy() << endl;

    for (unsigned int i = 5; i < 10; i++) {
        b->write(i * 10);
    }
    cout << "Current buffer occupancy: " << b->occupancy() << endl;

    delete b;
    return 0;
}
