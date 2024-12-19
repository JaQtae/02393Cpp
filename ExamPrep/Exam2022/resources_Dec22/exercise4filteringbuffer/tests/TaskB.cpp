#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    CountingBuffer *cb = new CountingBuffer(-1);
    Buffer *b = cb; // Just an alias for 'cb' above, but using the superclass

    cout << "Finding the frequency for value 0 returns: " << cb->frequency(0) << endl;
    cout << "Finding the frequency for value -1 returns: " << cb->frequency(-1) << endl;

    b->write(1); b->write(2); b->write(2); b->write(4);
    cout << "Finding the frequency for value 1 returns: " << cb->frequency(1) << endl;
    cout << "Finding the frequency for value 2 returns: " << cb->frequency(2) << endl;
    cout << "Finding the frequency for value 4 returns: " << cb->frequency(4) << endl;
    
    b->write(1); b->write(6); b->write(1);
    cout << "Finding the frequency for value 1 now returns: " << cb->frequency(1) << endl;
    cout << "Finding the frequency for value 6 returns: " << cb->frequency(6) << endl;
    
    delete cb;
    return 0;
}
