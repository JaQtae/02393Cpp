#include <iostream>
#include <numeric>  // For std::gcd
#include <string> 
using namespace std;

class fraction {
private:
    int numerator;
    int denominator;

    // Helper function calculating the greatest common divisor (gcd) and simplify the fraction

    void simplify() {
        int gcd_value = gcd(numerator, denominator);
        numerator /= gcd_value;
        denominator /= gcd_value;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {
        simplify();
    }

    void add(const fraction& f) {
        numerator = numerator * f.denominator + f.numerator * denominator;
        denominator *= f.denominator;
        simplify();
    }

    void mult(const fraction& f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
        simplify();
    }

    void div(const fraction& f) {
        numerator *= f.denominator; // Reciprocal multiplication
        denominator *= f.numerator;
        simplify();
    }

    void display() const {
        cout << numerator << " / " << denominator << endl;
    }
};

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
