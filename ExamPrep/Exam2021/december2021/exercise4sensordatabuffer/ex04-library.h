#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

// Include whats relevant
#include <vector>
#include <map>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here

class SensorBuffer : public Buffer {
private:
    // What is relevant for methods in .cpp
    int default_value;
    unsigned int count;
    vector<int> buffer;
    map<int, unsigned int> occurences;
public:
    // Constructor and Destructor
    SensorBuffer(int default_value);
    ~SensorBuffer();
    // Inherited from Buffer, overrride
    void write(int v) override;
    int read() override;
    // Additional methods
    int readAvg();
    unsigned int writeCount();

};

#endif /* EX04_LIBRARY_H_ */
