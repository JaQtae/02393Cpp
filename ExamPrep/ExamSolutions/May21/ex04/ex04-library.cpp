#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of FilteringBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and occupancy()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of reset()

FilteringBuffer::FilteringBuffer(int defaultValue) {
    this->defaultValue = defaultValue;
}

void FilteringBuffer::write(int v) {
    if (this->memory.find(v) != this->memory.end()) {
        return;
    }
    this->data.push_back(v);
    this->memory.insert(v);
}

unsigned int FilteringBuffer::occupancy() {
    return this->data.size();
}

int FilteringBuffer::read() {
    if (this->data.size() == 0) {
        return this->defaultValue;
    }

    int ret = this->data[0];
    this->data.erase(this->data.begin());

    return ret;
}

void FilteringBuffer::reset() {
    this->data.clear();
    this->memory.clear();
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}