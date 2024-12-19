#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of CountingBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write() and frequency(int v)

// Task 4(c).  Write a working implementation of mostFrequent()

// Task 4(d).  Write a working implementation of clear()

CountingBuffer::CountingBuffer(int defaultValue) {
    this->defaultValue = defaultValue;
    this->mostFrequentValue = defaultValue;
    this->mostFrequentCount = 0;
}

void CountingBuffer::write(int v) {
    this->data.push_back(v);
    
    if (this->occurrences.find(v) == this->occurrences.end()) {
        // Value has not been observed yet
        this->occurrences[v] = 1;
    } else {
        // Increment the occurrences for this value
        this->occurrences[v]++;
    }

    if (this->mostFrequentCount <= this->occurrences[v]){
        // Value is the most frequent
        this->mostFrequentValue = v;
        this->mostFrequentCount = this->occurrences[v];
    }
}

unsigned int CountingBuffer::frequency(int v) {
    if (this->occurrences.find(v) == this->occurrences.end()) {
        return 0;
    }

    return this->occurrences[v];
}

int CountingBuffer::mostFrequent() {
    return mostFrequentValue;
}

void CountingBuffer::clear() {
    this->data.clear();
    this->occurrences.clear();
    
    this->mostFrequentValue = defaultValue;
    this->mostFrequentCount = 0;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
