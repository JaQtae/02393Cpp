#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) return 1; // F_0 = 1, F_1 = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Sum of the prior two Fibonacci numbers
}

int main() {
    int n;
    string input;
    getline(cin, input);
    stringstream ss(input); // Terminate on enter...

    while (ss >> n) {
        cout << fibonacci(n) << " "; // 
    }
    return 0;
}