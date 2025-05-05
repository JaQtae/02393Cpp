#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class BoundedBuffer, by extending Buffer
// Write your code here

class BoundedBuffer : public Buffer {
private:
    int upper_bound, default_value; // input parameters
    unsigned int writes;
    vector<int> buffer;
    map<int, unsigned int> occurences;
public:
    BoundedBuffer(int upper_bound, int default_value);
    ~BoundedBuffer();
    void write(int v) override;
    int read() override;
    unsigned int occupancy() override;
    // Additional methods
    unsigned int setBound(int v);
};

#endif /* EX04_LIBRARY_H_ */
