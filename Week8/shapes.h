// shapes.h
#ifndef SHAPES_H
#define SHAPES_H

// Base class Shape
class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual double height() const = 0;
    virtual double width() const = 0;
    virtual void rotate() = 0; // Rotate 90 degrees
    virtual ~Shape() {} // Virtual destructor
};

// Rectangle class
class Rectangle : public Shape {
private:
    double h, w;

public:
    Rectangle(double height, double width);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override;
};

// Square class, derived from Rectangle
class Square : public Rectangle {
public:
    Square(double side);
    void rotate() override; // Rotation has no effect on a square
};

// Circle class
class Circle : public Shape {
private:
    double r;

public:
    Circle(double radius);
    double area() const override;
    double perimeter() const override;
    double height() const override;
    double width() const override;
    void rotate() override; // Rotation has no effect on a circle
};

#endif
