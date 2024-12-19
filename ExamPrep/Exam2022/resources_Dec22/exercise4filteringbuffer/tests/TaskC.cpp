#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    CountingBuffer *cb = new CountingBuffer(-10);
    Buffer *b = cb; // Just an alias for 'cb' above, but using the superclass

    cout << "Most frequent value is: " << cb->mostFrequent() << endl;

    b->write(1); b->write(42);
    cout << "Most frequent value now is: " << cb->mostFrequent() << endl;

    b->write(4); b->write(5); b->write(1);
    cout << "Most frequent value now is: " << cb->mostFrequent() << endl;

    b->write(42);
    cout << "Most frequent value now is: " << cb->mostFrequent() << endl;

    b->write(8); b->write(1); b->write(3);
    cout << "Most frequent value now is: " << cb->mostFrequent() << endl;

    delete cb;
    return 0;
}
