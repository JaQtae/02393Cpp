#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of LimitedBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and occupancy()

// Task 4(c).  Write a working implementation of read()

LimitedBuffer::LimitedBuffer(unsigned int maxElements, int defaultValue) {
    this->maxElements = maxElements;
    this->defaultValue = defaultValue;
}

void LimitedBuffer::write(int v) {
    if (this->data.size() == this->maxElements) {
        return;
    }
    this->data.push_back(v);
}

unsigned int LimitedBuffer::occupancy() {
    return this->data.size();
}

int LimitedBuffer::read() {
    if (this->data.size() == 0) {
        return this->defaultValue;
    }

    int ret = this->data[0];
    this->data.erase(this->data.begin());

    return ret;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}