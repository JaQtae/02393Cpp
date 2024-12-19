#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of SensorBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and writeCount()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of readAvg()

SensorBuffer::SensorBuffer(unsigned int averageNo) {
    this->averageNo = averageNo;
}

void SensorBuffer::write(int v) {
    this->data.push_back(v);
    this->writeCounter++;

    if (this->writeCounter > this->averageNo) {
        // We only keep the latest necessary values in 'data'
        data.erase(data.begin());
    }
}

unsigned int SensorBuffer::writeCount() {
    return this->writeCounter;
}

int SensorBuffer::read() {
    if (this->writeCounter == 0) {
        return 0;
    } else {
        return this->data.back();
    }
}

int SensorBuffer::readAvg() {
    if (this->writeCounter == 0) {
        return 0;
    }

    int sum = 0; // Will store the sum of buffer values

    // Number of values we can use to compute the average
    unsigned int nvalues = min(this->writeCounter, this->averageNo);

    for (unsigned int i = 0; i < nvalues; i++) {
        sum += this->data[i];
    }

    return sum / nvalues;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
