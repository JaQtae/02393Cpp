#include "ex04-library.h"

#include <cmath>
#include <iostream>
using namespace std;

// Task 4(a).  Write a placeholder implementation of AutoSummingBuffer's
//             constructor and methods
// Constructor
AutoSummingBuffer::AutoSummingBuffer(unsigned int max_buffer_capacity, int default_value) {
    // Placeholder implementation of AutoSummingBuffer constructor
    // e.g. all parameters can do nothing.
    this->max_buffer_capacity = max_buffer_capacity; // Initialize max_buffer_capacity
    this->default_value = default_value;             // Initialize default_value
    this->writes = 0;
}
AutoSummingBuffer::~AutoSummingBuffer() {} // empty destructor


// Task 4(b).  Write a working implementation of write(int v) and occupancy()
void AutoSummingBuffer::write(int v) { // append v to buffer, if exceed capacity, then
    // oldest val in buffer replaced by sum of oldest val within buffer capacity and the oldest value beyond capacity
    this->buffer.push_back(v);
    this->writes++;
    if(this->writes > this->max_buffer_capacity) {
        int oldSum = this->buffer[0];
        this->buffer.erase(this->buffer.begin());
        this->buffer[0] = this->buffer[0] + oldSum;
    }
}

unsigned int AutoSummingBuffer::occupancy() {
    if (this->writes < this->max_buffer_capacity) {
        return writes; // Return number of writes if below capacity
    } else {
        return max_buffer_capacity; // Return max capacity if writes exceed it
    }; 
}
// Task 4(c).  Write a working implementation of read()
int AutoSummingBuffer::read() {
    if (this->buffer.size() > 0) {
        int value = this->buffer[0]; // Get the first value
        this->buffer.erase(this->buffer.begin()); // Remove the first value
        if (this->writes > this->max_buffer_capacity) {
            this->writes = this->max_buffer_capacity - 1; // Adjust writes if it exceeds capacity
        } else {
            this->writes--;
        }
        return value; // Return the read value
    } else {
        return this->default_value; // Return default value if buffer is empty
    }
}


// Task 4(d).  Write a working implementation of occurrences(int v)
unsigned int AutoSummingBuffer::occurrences(int v) {
    unsigned int occurrences = 0;
    for (auto it = this->buffer.begin(); it != this->buffer.end(); it++) {
        if (*it == v){
            occurrences++;
        }
    }
    return occurrences;
}
// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
