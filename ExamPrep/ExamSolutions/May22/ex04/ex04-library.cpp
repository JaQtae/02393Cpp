#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and faults()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of clear()

SensorBuffer::SensorBuffer(int defaultValue, int min, int max) {
    this->defaultValue = defaultValue;
    this->min = min;
    this->max = max;
    this->faultsCount = 0;
}

void SensorBuffer::write(int v) {
    if ((v >= this->min) && (v <= this->max)) {
        this->data.push_back(v);
    } else if (v < this->min) {
        this->data.push_back(this->min);
        this->faultsCount++;
    } else {
        this->data.push_back(this->max);
        this->faultsCount++;
    }
}

unsigned int SensorBuffer::faults() {
    return this->faultsCount;
}

int SensorBuffer::read() {
    if (this->data.size() == 0) {
        return this->defaultValue;
    } else {
        int ret = this->data[0];
        this->data.erase(this->data.begin());
        return ret;
    }
}

void SensorBuffer::clear() {
    while (this->data.size() > 0) {
        this->read();
    }
    this->faultsCount = 0;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
