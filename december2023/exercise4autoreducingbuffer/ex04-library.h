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

// Task 4(a).  Declare the class AutoReducingBuffer, by extending Buffer
// Write your code here


class AutoReducingBuffer : public Buffer {

private:
    // Here you have to define the required parameters. 
    // You can also write extra stuff that can help you in the coding tasks
    // e.g. vector or a write incrementer
    vector<int> data;
    unsigned int max_buffer_capacity;
    int default_value;
    unsigned int writes = 0;

public:
    
    AutoReducingBuffer(unsigned int max_buffer_capacity, int default_value); // Constructor
    ~AutoReducingBuffer(); // destructor
    void write(int v) override;
    int read() override;
    unsigned int occupancy() override;
    bool contains(int v);
};




// Remember to go and add '../' to the library.h file in /tests, or else it won't compile.
// You do not need to copy it into the folder, then you need to change it every time you make changes

#endif /* EX04_LIBRARY_H_ */
