#include <iostream>
#include "ex04-library.h"
using namespace std;

int main() {
    CountingBuffer *cb = new CountingBuffer(-999);
    Buffer *b = cb; // Just an alias for 'cb' above, but using the superclass

    cout << "Most frequent value is: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 0 returns: " << cb->frequency(0) << endl;
    cout << "Finding the frequency for value -999 returns: " << cb->frequency(-999) << endl;

    b->write(2); b->write(20); b->write(2); 
    cout << "Most frequent value now is: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 2 returns: " << cb->frequency(2) << endl;
    cout << "Finding the frequency for value -999 returns: " << cb->frequency(-999) << endl;

    b->clear();

    cout << "Cleared.  Most frequent value is: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 2 returns: " << cb->frequency(2) << endl;
    cout << "Finding the frequency for value -999 returns: " << cb->frequency(-999) << endl;

    b->write(11); b->write(0); b->write(-999);
    cout << "Most frequent value now is: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 11 returns: " << cb->frequency(11) << endl;
    cout << "Finding the frequency for value -999 returns: " << cb->frequency(-999) << endl;

    b->clear();

    cout << "Cleared.  Most frequent value is: " << cb->mostFrequent() << endl;
    cout << "Finding the frequency for value 11 returns: " << cb->frequency(11) << endl;
    cout << "Finding the frequency for value -999 returns: " << cb->frequency(-999) << endl;

    delete b;
    return 0;
}
