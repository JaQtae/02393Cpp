#include "vector2d.h"
#include <cmath>


// Constructor: vector with components a and b
v2d::v2d(double a, double b) {
    x = a;
    y = b;
}
// Copy constructor: Build vector identical to v
v2d::v2d(const v2d & v) {
    x = v.x;
    y = v.y;
}
// Destructor: Does nothing special :)
v2d::~v2d() {}

// Assignment op.: Update vector to be identical to v
v2d & v2d::operator=(const v2d &v) {
    // "this" is a pointer to the current instance of the class (ie. the object on which a member function is invoked)
    if (this != &v) { // Avoid self-assignment
        x = v.x;
        y = v.y;
    } return *this; // Access the object itself (not a new object is returned) [operator overloading/method chaining]
}
// Addition op.: Update vector by adding v
v2d & v2d::operator+(const v2d &v) {
    this->x += v.x;
    this->y += v.y;
    return *this;
}

// Scalar product: Multiply vector by another vector v and return **without** updating vector
double v2d::operator*(const v2d &v) {
    return (x * v.x) + (y * v.y); // only returns the calculation result, not an object
}
// Scalar multiplication: Update vector by scaling by k
v2d & v2d::operator*(double k) {
    x *= k;
    y *= k;
    return *this;
}
// Length computation
double v2d::length() {
    return sqrt((*this) * (*this));
}

