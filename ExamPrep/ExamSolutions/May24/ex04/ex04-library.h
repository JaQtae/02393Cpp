#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class AutoReducingBuffer, by extending Buffer
// Write your code here
#include <vector>
using namespace std;

class AutoSummingBuffer: public Buffer {
private:
    vector<int> data;
    int defaultValue;
    unsigned int capacity;
    unsigned int writes;
public:
    AutoSummingBuffer(unsigned int capacity, int defaultValue);
    virtual void write(int v);
    virtual int read();
    virtual unsigned int occupancy();
    unsigned int occurrences(int v);
};

#endif /* EX04_LIBRARY_H_ */
