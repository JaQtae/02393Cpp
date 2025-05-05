#include "ex04-library.h"

#include <cmath>
#include <algorithm>

// Task 4(a).  Write a placeholder implementation of BoundedBuffer's
//             constructor and methods
BoundedBuffer::BoundedBuffer(int upper_bound, int default_value){
    this->upper_bound = upper_bound;
    this->default_value = default_value;
    this->writes = 0;
}
BoundedBuffer::~BoundedBuffer(){}


// void BoundedBuffer::write(int v) {

// }
// int BoundedBuffer::read() {
//     return 0;
// }
// unsigned int BoundedBuffer::occupancy() {
//     return 0;
// }

// unsigned int BoundedBuffer::setBound(int v){
//     return 0;
// }



// Task 4(b).  Write a working implementation of write(int v) and occupancy()
void BoundedBuffer::write(int v) {
    // If below upper bound:
    if (v < this->upper_bound){
        this->buffer.push_back(v); // Append current v to buffer vector
        this->occurences[buffer.back()]++; // Store occurence of v
        this->writes++;
    }

}
unsigned int BoundedBuffer::occupancy() {
    return this->writes;
}
// Task 4(c).  Write a working implementation of read()

int BoundedBuffer::read() {
    // Removes oldest value of buffer and returns it
    // occupancy must decrease by one

    // IF buffer is empty, return default value
    if(this->buffer.size()>0) {
        int value = this->buffer[0];
        this->buffer.erase(this->buffer.begin());
        this->writes--; // Decrement occupancy
        return value;
    } else {
        return this->default_value;
    }
    return 0;
}

// Task 4(d).  Write a working implementation of setBound(int v)

unsigned int BoundedBuffer::setBound(int v){
    this->upper_bound = v; // new upper bound

    // Remove all values in buffer below this bound
    // for each thing in buffer

    unsigned int val_removed_from_buffer = 0;
    sort(this->buffer.begin(), this->buffer.end());


    for (auto it = this->buffer.begin(); it < this->buffer.end(); it++) {
        // Misunderstanding pointer it somehow...
        if (*it > this->upper_bound){
            this->buffer.erase(it);
            val_removed_from_buffer++;
            this->writes--;
        }
    }
    return val_removed_from_buffer;

}


// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
