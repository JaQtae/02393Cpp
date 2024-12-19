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
    unsigned int averageNo;
    unsigned int writeCounter;
public:
    SensorBuffer(unsigned int averageNo);
    void write(int v);
    unsigned int writeCount();
    int read();
    int readAvg();
};

#endif /* EX04_LIBRARY_H_ */
