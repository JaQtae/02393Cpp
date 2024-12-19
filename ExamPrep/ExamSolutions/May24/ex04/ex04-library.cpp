#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of AutoSummingBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write(int v) and occupancy()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of occurrences(int v)

AutoSummingBuffer::AutoSummingBuffer(unsigned int capacity, int defaultValue) {
    this->defaultValue = defaultValue;
    this->capacity = capacity;
    this->writes = 0;
}

unsigned int AutoSummingBuffer::occupancy() {
    if(this->writes < this->capacity) {
        return writes;
    } else {
        return capacity;
    }
}

void AutoSummingBuffer::write(int v) {
    this->data.push_back(v);
    this->writes++;
    if(this->writes > this->capacity) {
        int oldSum = this->data[0];
        this->data.erase(this->data.begin());
        this->data[0] = this->data[0] + oldSum;
    }
}

int AutoSummingBuffer::read() {
    if(this->data.size()>0) {
        int value = this->data[0];
        this->data.erase(this->data.begin());
        if (this->writes > this->capacity) {
            this->writes = this->capacity - 1;
        } else {
            this->writes--;
        }
        return value;
    } else {
        return this->defaultValue;
    }
}

unsigned int AutoSummingBuffer::occurrences(int v) {
    unsigned int occurrences = 0;
    for (auto it = this->data.begin(); it != this->data.end(); it++) {
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
