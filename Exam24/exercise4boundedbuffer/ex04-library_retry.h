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


#endif /* EX04_LIBRARY_H_ */
