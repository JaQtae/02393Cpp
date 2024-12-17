#include <iostream>
#include <cmath>
using namespace std;

double Leibniz_pi(int n) {
    double pi_approx = 0.0;

    for (int i = 0; i < n; ++i) {
        pi_approx +=  (pow(-1, i)) / (2*i + 1) ;
    }
    return 4 * pi_approx;
}

int main () {
    int n;
    cin >> n;
    cout << Leibniz_pi(n) << endl;
    return 0;

}