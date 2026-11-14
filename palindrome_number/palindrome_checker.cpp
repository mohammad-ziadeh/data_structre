#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class palindrome {
    vector<int> digits_;

    void digit_breaker(int num) {
        while (num > 0) {
            digits_.push_back(num % 10); // will add tem to the vector in revers order example 153 will be 351
            num /= 10;
        }
    }

    int flipped_digits(const int num) {
        digit_breaker(num);
        int sum = 0;
        for (int i = 0; i < digits_.size(); ++i) {
            sum = (sum * 10) + digits_.at(i);
        }
        return sum;
    }

public:
    bool is_palindrome(int num) {
        digits_.clear();
        if (num < 0) {
            num *= -1;
        }
        return num == flipped_digits(num);
    }
};

int main() {
    palindrome a;
    cout << a.is_palindrome(-707) << endl;
    cout << a.is_palindrome(152) << endl;
    cout << a.is_palindrome(404) << endl;
    cout << a.is_palindrome(354676453) << endl;
    return 0;
}
