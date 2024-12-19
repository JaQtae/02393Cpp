#include "ex04-library.h"

// Task 4(a).  Write a placeholder implementation of CountingBuffer's
//             constructor and methods

//-------------- NOTE ---------------//
// IF YOU HAVE MADE YOUR .h FILE, MOVE IT INTO THE tests/ FOLDER //
// OTHERWISE YOU GET AN ERROR THAT IT CANT FIND IT WHEN YOU DO YOUR TEST FOR
// TASK A!!!!!!
// ----------------------------------//

// Constructor
CountingBuffer::CountingBuffer(int default_value) {//, unsigned int occurences, int mostFrequent) {
    // Initialize 
    this->default_value = default_value;
    this->mostFrequentValue = default_value; // sigh...
    this->highestCount = 0;
}

// Methods of Class:
// remember to add the same types
void CountingBuffer::write(int v) {
    // Since we have to keep count of:
    // 1. Number of times we've seen value v being written TO buffer object
    // 2. Which the most frequent value is OF BUFFER OBJECT
    // We can either do some funny stuff or write it into the constructor and class
    
    // IDEAL IS USING MAP e.g. IN CLASS map<int, unsigned int> occurences;
    // Has to be something where we use <data type, data type>.
    // In this case, we want to use <v, frequency>, and frequency()-function is unsigned int!!!
    this->buffer.push_back(v); // Append current v to buffer vector

    this->occurences[buffer.back()]++; // Increment last value put into buffer in occurences

    // if frequency of v is larger OR equal to current highestCount
    if (this->occurences[v] >= this->highestCount){
        this->highestCount = this->occurences[v]; // times v seen
        this->mostFrequentValue = v; // Last v value seen
    }



}
CountingBuffer::~CountingBuffer() {
    // Empty 
}
void CountingBuffer::clear() {
    // Empty
    this->buffer.clear();
    this->occurences.clear();
    this->mostFrequentValue = this->default_value; // Reset to default
    this->highestCount = 0;

}
// Non-void functions have to return something.
unsigned int CountingBuffer::frequency(int v) {
    if (this->occurences.find(v) == this->occurences.end()){
        return 0; // We couldn't find v in our mapping
    }
    return this->occurences[v];
}

int CountingBuffer::mostFrequent() {
    return this->mostFrequentValue;
}


// Task 4(b).  Write a working implementation of write() and frequency()

// Task 4(c).  Write a working implementation of mostFrequent()

// Task 4(d).  Write a working implementation of clear()

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
