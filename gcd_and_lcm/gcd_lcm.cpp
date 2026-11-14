#include <iostream>
#include <vector>
using namespace std;

// Greatest Common Divisor (GCD)
int gcd(const int a, const int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Least Common Multiple (LCM)
int lcm(const int a, const int b) {
    if (a == 0 || b == 0) {
        return 0;
    }
    return (a / gcd(a, b)) * b;
}

int main() {
    cout << gcd(48, 18) << endl;
    cout << lcm(48, 18) << endl;
    return 0;
}
