#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of AutoReducingBuffer's
//             constructor and methods

// Task 4(b).  Write a working implementation of write(int v) and occupancy()

// Task 4(c).  Write a working implementation of read()

// Task 4(d).  Write a working implementation of contains(int v)

AutoReducingBuffer::AutoReducingBuffer(unsigned int capacity, int defaultValue) {
    this->defaultValue = defaultValue;
    this->capacity = capacity;
    this->writes = 0;
}

unsigned int AutoReducingBuffer::occupancy() {
    if(this->writes < this->capacity) {
        return writes;
    } else {
        return capacity;
    }
}

void AutoReducingBuffer::write(int v) {
    this->data.push_back(v);
    this->writes++;
    if(this->writes > this->capacity) {
        int oldAvg = this->data[0];
        this->data.erase(this->data.begin());
        int divider = this->writes - this->capacity;
        this->data[0] = (this->data[0] + oldAvg * divider) / (divider + 1);
    }
}

int AutoReducingBuffer::read() {
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

bool AutoReducingBuffer::contains(int v) {
    for (auto it = this->data.begin(); it != this->data.end(); it++) {
        if (*it == v){
            return true;
        }
    }
    return false;
}


// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
