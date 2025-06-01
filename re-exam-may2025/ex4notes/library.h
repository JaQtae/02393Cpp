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




// class <Class-Name> : public <Extending-Class> {

// private:
    // Here you have to define the required parameters. 
    // You can also write extra stuff that can help you in the coding tasks
    // e.g. vector or a write incrementer

// public:
    //
    // <Class-Name>(<params>); // Constructor
    // ~<Class-Name>(); // destructor
    // <function1(<params>)> override; // ----------- overrides
    // <function2> override;
    // ...
    // <function4(<params>)>; // Additional method
// };




// Remember to go and add '../' to the library.h file in /tests, or else it won't compile.
// You do not need to copy it into the folder, then you need to change it every time you make changes