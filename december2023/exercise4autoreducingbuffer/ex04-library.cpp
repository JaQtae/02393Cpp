#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of AutoReducingBuffer's
//             constructor and methods

AutoReducingBuffer::AutoReducingBuffer(unsigned int max_buffer_capacity, int default_value) {
    this->max_buffer_capacity = max_buffer_capacity;
    this->default_value = default_value;
    unsigned int writes = 0;
} // Constructor

AutoReducingBuffer::~AutoReducingBuffer() {}; // destructor


void AutoReducingBuffer::write(int v) {
}
int AutoReducingBuffer::read() {
    return 0;
}
unsigned int AutoReducingBuffer::occupancy() {
    return 0;
}
bool AutoReducingBuffer::contains(int v) {
    return false;
}

// Task 4(b).  Write a working implementation of write(int v) and occupancy()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of contains(int v)

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
