#include <iostream>
#include <sstream>

#include "ex1.h"

using namespace std;

// Initialize the constructor: We pass the arguments and initialize 'fraction' class
fraction::fraction(int n, int d) {
    if (d == 0) {
        cerr << "Error: Denominator cannot be zero." << endl;
        numerator = 0;
        denominator = 1; // Default to 1 if denominator is zero
    } else {
        numerator = n;
        denominator = d;
    }
    simplify();
}
// Destructor. Leave.
fraction::~fraction() {}


//Week 6

void fraction::add(fraction f) {
    numerator = numerator * f.denominator + f.numerator * denominator;
    denominator *= f.denominator;
    simplify(); // Pass to simplifier method
}
void fraction::mult(fraction f){
    numerator *= f.numerator;
        denominator *= f.denominator;
        simplify();
}
void fraction::div(fraction f){
    numerator *= f.denominator; // Reciprocal multiplication
    denominator *= f.numerator;
    simplify();
}

void fraction::display() {
    cout << numerator << " / " << denominator << endl;
}



int main() {
    while (true) {
        string op;
        int a, b, c, d;
        char slash1, slash2;
        cin >> a >> slash1 >> b >> op >> c >> slash2 >> d;
        if (cin.fail()) break;

        fraction f1(a,b), f2(c,d);

        if (op == "+") {
            f1.add(f2);
        } else if (op == "*") {
            f1.mult(f2);
        } else if (op == "div") { 
            f1.div(f2);
        }

        f1.display();
    }

    return 0;

}