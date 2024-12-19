#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual void reset() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class FilteringBuffer, by extending Buffer
// Write your code here
#include <set>
#include <vector>
using namespace std;

class FilteringBuffer: public Buffer {
private:
    vector<int> data;
    int defaultValue;
    set<int> memory; // Here we store the values we have already observed
public:
    FilteringBuffer(int defaultValue);
    void write(int v);
    int read();
    unsigned int occupancy();
    void reset();
};

#endif /* EX04_LIBRARY_H_ */
