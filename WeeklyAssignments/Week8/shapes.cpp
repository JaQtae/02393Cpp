#define _USE_MATH_DEFINES

#include "shapes.h"
#include <cmath>
#include <algorithm>
using namespace std;
// shapes.cpp

// Rectangle class definitions
Rectangle::Rectangle(double height, double width) : h(height), w(width) {}

double Rectangle::area() const {
    return h * w;
}

double Rectangle::perimeter() const {
    return 2 * (h + w);
}

double Rectangle::height() const {
    return h;
}

double Rectangle::width() const {
    return w;
}

void Rectangle::rotate() {
    std::swap(h, w);
}

// Square class definitions
Square::Square(double side) : Rectangle(side, side) {}

void Square::rotate() {
    // Rotation does not change a square
}

// Circle class definitions
Circle::Circle(double radius) : r(radius) {}

double Circle::area() const {
    return M_PI * r * r;
}

double Circle::perimeter() const {
    return 2 * M_PI * r;
}

double Circle::height() const {
    return 2 * r;
}

double Circle::width() const {
    return 2 * r;
}

void Circle::rotate() {
    // Rotation does not change a circle
}
