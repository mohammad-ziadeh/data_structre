#include <iostream>

using namespace std;

// 3

static int getFactorial(const int num) {
    if (num <= 0) {
        return 1;
    }
    return num * getFactorial(num - 1);
}

int main() {
    int number;
    cout << "Enter any number above 0:" << endl;
    cin >> number;

    if (number < 0) {
        cout << "The number should be bigger than 0" << endl;
    } else {
        cout << getFactorial(number);
    }

    return 0;
}
