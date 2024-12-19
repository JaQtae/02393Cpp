#include <iostream>

using namespace std;

int main() {
    double x, y, z; // Stores up to 7 decimal points and rounds off the rest of the digits.
                    // should always use over float, kind of... https://www.freecodecamp.org/news/double-vs-float-in-cpp-the-difference-between-floats-and-doubles/
    cout << "";
    cin >> x;
    cout << "";
    cin >> y;
    cout << "";
    cin >> z;

    double result = (x + y) - z; // Declare object type even for the output!

    cout << result << endl; // Could "Result is: " << result, but Exercise doesn't tell us to?

    return 0;
}