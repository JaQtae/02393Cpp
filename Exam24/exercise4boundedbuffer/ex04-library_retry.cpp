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

}
// Task 4(c).  Write a working implementation of read()

int BoundedBuffer::read() {
 return 0; // Placeholder return value
}

// Task 4(d).  Write a working implementation of setBound(int v)
unsigned int BoundedBuffer::setBound(int v){
    return 0; // Placeholder return value
}


// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
