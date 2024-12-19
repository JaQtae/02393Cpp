#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

#include <vector>
#include <map>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual void clear() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class CountingBuffer, by extending Buffer
// Write your code here
 // Remember to make it PUBLIC accessible buffer object
class CountingBuffer : public Buffer {
private:
    // Defined by one parameter, default_value.
    int default_value, mostFrequentValue, highestCount;
    vector<int> buffer; // book keeping?
    map<int, unsigned int> occurences; // Book keeping for frequency() and mostFrequent()
    // unsigned int occurences;
    // int mostFrequent;
public:
    CountingBuffer(int default_value); // Initialize
    ~CountingBuffer();
    void write(int v) override;
    void clear() override;
    // Additional, non-overridden methods given (a)
    unsigned int frequency(int v);
    int mostFrequent();

};

#endif /* EX04_LIBRARY_H_ */
