#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual void clear() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class SensorBuffer, by extending Buffer
// Write your code here
#include <vector>
#include <map>
using namespace std;

class CountingBuffer: public Buffer {
private:
    vector<int> data;
    map<int,unsigned int> occurrences;
    int mostFrequentValue, defaultValue;
    unsigned int mostFrequentCount;
public:
    CountingBuffer(int defaultValue);
    void write(int v);
    unsigned int frequency(int v);
    int mostFrequent();
    void clear();
};

#endif /* EX04_LIBRARY_H_ */
