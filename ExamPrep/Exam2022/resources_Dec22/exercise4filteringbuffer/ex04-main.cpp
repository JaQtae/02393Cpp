#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    CountingBuffer *cb = new CountingBuffer(-1);
    Buffer *b = cb; // Just an alias for 'cb' above, but using the superclass

    cout << "Most frequent value: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 0 returns: " << cb->frequency(0) << endl;

    b->write(9); b->write(7);
    cout << "Wrote 9 and 7. Most frequent value: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 9 returns: " << cb->frequency(7) << endl;
    cout << "Finding the frequency for value 7 returns: " << cb->frequency(9) << endl;

    b->write(3); b->write(9);
    cout << "Wrote 3 and 9. Most frequent value: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 3 returns: " << cb->frequency(3) << endl;
    cout << "Finding the frequency for value 9 returns: " << cb->frequency(9) << endl;

    b->clear();
    cout << "Buffer cleared. Most frequent value: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 9 now returns: " << cb->frequency(9) << endl;

    delete cb;
    return 0;
}
