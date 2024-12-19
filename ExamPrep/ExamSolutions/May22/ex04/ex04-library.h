#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here
#include <vector>
using namespace std;

class SensorBuffer: public Buffer {
private:
    vector<int> data;
    int defaultValue, min, max;
    unsigned int faultsCount;
public:
    SensorBuffer(int defaultValue, int min, int max);
    void write(int v);
    int read();
    unsigned int faults();
    void clear();
};

#endif /* EX04_LIBRARY_H_ */
