#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class armstrong {
    vector<int> digits_;

public:
    void break_number(int num) {
        while (num > 0) {
            digits_.push_back(num % 10);
            num /= 10;
        }
    }

    int get_left_side_value() const {
        int sum = 0;
        for (const int digit: digits_) {
            sum = sum + pow(digit, digits_.size());
        }
        return sum;
    }

    int get_right_side_value() const {
        int sum = 0;
        for (int i = 0; i < digits_.size(); ++i) {
            sum = sum + (digits_.at(i) * pow(10, i));
        }
        return sum;
    }

    bool is_armstrong_num(const int num) {
        digits_.clear();
        break_number(num);
        return get_left_side_value() == get_right_side_value();
    }
};

int main() {
    armstrong a;

    cout << a.is_armstrong_num(153) << endl; // expected 1
    cout << a.is_armstrong_num(1634) << endl; // expected 1
    cout << a.is_armstrong_num(100) << endl; // expected 0

    return 0;
}
