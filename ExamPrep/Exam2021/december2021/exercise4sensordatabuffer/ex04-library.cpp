#include "ex04-library.h"

#include <iostream>
// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods

// Constructor and Destructor
SensorBuffer::SensorBuffer(int default_value) {
    this->default_value = default_value; // used in methods
    this->count = 0; // used in methods
}
SensorBuffer::~SensorBuffer() {
    // Empty destructor
}
// void SensorBuffer::write(int v) {
//     return; // Void dont need return types
// }
// int SensorBuffer::read() {
//     return 0;
// }
// // Additional methods
// int SensorBuffer::readAvg() {
//     return 0;
// }
// unsigned int SensorBuffer::writeCount() {
//     return 0;
// }

// Task 4(b).  Write a working implementation of write() and writeCount()
void SensorBuffer::write(int v) {
    // Store v such that it can be used in read() and readAvg()
    // and increment counter used in writeCount()

    // We need a structure which can keep track of v and of its count
    // Let's use a vector for the v (data) and a map for its count 
    // Mapping map<v, occurences(of v)>. ALTER ex04-library.h file!!

    this->buffer.push_back(v); // Save v in buffer
    this->occurences[buffer.back()]++; // Increment v occurence in occurence map

    // Keep track of times write() has been invoked
    this->count = buffer.size(); // Every time we've saved v
}
unsigned int SensorBuffer::writeCount() {
    return this->count;
}

// Task 4(c).  Write a working implementation of read()
int SensorBuffer::read() {
    // Returns most recent value written in buffer:
    // Equivalently: buffer[buffer.size() - 1];
    // Special case: write() never used, return 0
    if (this->count == 0) {
        return 0;
    }
    return buffer.back();
}
// Task 4(d).  Write a working implementation of readAvg()
int SensorBuffer::readAvg() {
    // Average of recent values in buffer, up to n values, where n is
    // input to SensorBuffer constructor.
    // So for our case default_value = n.

    int sum = 0;
    // Special case: write() never used, return 0
    if (this->count == 0) {
        return 0;
    }

    // if write() called m times (0 < m < n)
    if (this->count < this->default_value){
        for (size_t i = (this->buffer.size() - this->count); i < this->buffer.size() ; i++){
            sum += this->buffer[i]; // Sum each element from n->end()
        }
        return (sum / this->count);
    }

    // *Latest* n values, e.g. starts at n -> end of buffer
    for (size_t i = (this->buffer.size() - default_value); i < this->buffer.size() ; i++){
        sum += this->buffer[i]; // Sum each element from n->end()
    }
    return (sum / default_value);
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
