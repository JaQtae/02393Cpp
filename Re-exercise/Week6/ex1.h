#include <iostream>
#include <numeric> 

using namespace std;

class fraction {
private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;
    // Helper function for greatest common divisor (GCD). Self-made.
    void simplify(){
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }
public:
    // Class constructor
    fraction(int n, int d);
    ~fraction();
    // Methods to update the fraction
    void add(fraction f);
    void mult(fraction f);
    void div(fraction f);
    // Display method
    void display(void);
};