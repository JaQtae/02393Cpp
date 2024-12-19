#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_
#include <vector>
using namespace std;

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual unsigned int occupancy() = 0;
    virtual ~Buffer();
};

// Task 4(a).  Declare the class AutoSummingBuffer, by extending Buffer
// Write your code here

// We write the class, which extends the Buffer class
class AutoSummingBuffer : public Buffer {
    // Takes 2 parameters
private:
    unsigned int max_buffer_capacity;
    int default_value; // used in (c)
    vector<int> buffer; // used in (b)


public:
    // Constructor, should *override* pure virtual methods of Buffer
    // (ie. those with =0). It should also add a method occurences()
    AutoSummingBuffer(unsigned int max_buffer_capacity, int default_value);// from .cpp
    ~AutoSummingBuffer(); // Destructor
    void write(int v) override;
    int read() override;
    unsigned int occupancy() override;
    unsigned int occurrences(int v); // can't override base member (its in cpp, not in Buffer class)
};

#endif /* EX04_LIBRARY_H_ */
