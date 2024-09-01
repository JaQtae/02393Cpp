#include <iostream>
#include <cmath>

using namespace std;

double pi(int n) {
    double leibniz = 0.0;
    
    for (int i = 0; i < n; ++i) {
        leibniz += pow(-1, i) / (2 * i + 1);   
    }
    return 4 * leibniz; // approximation of pi
}


int main() {
    int n;
    cin >> n;

    double approx_pi = pi(n);
    cout << approx_pi << endl;
    
    return 0;
}