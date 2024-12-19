#include "ex04-library.h"

#include <cmath>

// Task 4(a).  Write a placeholder implementation of AutoSummingBuffer's
//             constructor and methods

// Constructor
AutoSummingBuffer::AutoSummingBuffer(unsigned int max_buffer_capacity, int default_value) {
    // Placeholder implementation of AutoSummingBuffer constructor
    // e.g. all parameters can do nothing.
    this->max_buffer_capacity = max_buffer_capacity; // Initialize max_buffer_capacity
    this->default_value = default_value;             // Initialize default_value
}
AutoSummingBuffer::~AutoSummingBuffer() {
    // Empty destructor
}
// void AutoSummingBuffer::write(int v) {

// }
// int AutoSummingBuffer::read() {
//     return 0;
// }
// unsigned int AutoSummingBuffer::occupancy() {
//     return 0;
// }

// unsigned int AutoSummingBuffer::occurrences(int v) {
//     return 0;
// }


// Task 4(b).  Write a working implementation of write() and occupancy()
void AutoSummingBuffer::write(int v) {
    buffer.push_back(v); // Add the new value to the buffer

    // If buffer exceeds capacity
    if (buffer.size() > max_buffer_capacity) {
        // Sum the oldest value with the excess values beyond capacity
        int sum = buffer[0]; // Start with the oldest value
        for (unsigned int i = max_buffer_capacity; i < buffer.size(); ++i) {
            sum += buffer[i]; // Add the excess values
        }

        // Replace the oldest value with the calculated sum
        buffer[0] = sum;

        // Remove the excess elements beyond capacity
        buffer.erase(buffer.begin() + max_buffer_capacity, buffer.end());
    }
}
unsigned int AutoSummingBuffer::occupancy() {
    return buffer.size();
}

// -------DONT WORK----------//

// Task 4(c).  Write a working implementation of read()
int AutoSummingBuffer::read() {
    // Special case: buffer is empty, return default value specified in constructor
    if (buffer.empty()) {
        return default_value;
    }
    int oldest = buffer.front(); // Get oldest value
    // Remove it
    buffer.erase(buffer.begin()); 
    return oldest; // Return the oldest value
}

// Task 4(d).  Write a working implementation of occurrences(int v)
unsigned int AutoSummingBuffer::occurrences(int v) {
    unsigned int count = 0;
    for (unsigned int i = 0; i < buffer.size(); ++i) {
        if (buffer[i] == v) {
            ++count;
        }
    }
    return count;
}






// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
