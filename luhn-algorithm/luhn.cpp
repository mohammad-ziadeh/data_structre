#include <iostream>
#include <vector>
using namespace std;

class Luhn {
    vector<int> numbers_;
    vector<int> sum_numbers_;

public:
    void separate_numbers(const string &pin_code) {
        for (const char ch: pin_code) {
            if (ch >= '0' && ch <= '9') {
                numbers_.push_back(ch - '0');
            }
        }
    };

    bool is_single() const {
        return numbers_.size() % 2 != 0;
    }

    int sum_values() const {
        int sum = 0;
        for (const int num: sum_numbers_) {
            sum = sum + num;
        };
        return sum;
    }

    static int resolve_bigger_ten(const int num) {
        return num > 9 ? num - 9 : num;
    }

    void reset_vectors() {
        numbers_.clear();
        sum_numbers_.clear();
    }

    bool is_valid(const string &pin_code) {
        reset_vectors();
        separate_numbers(pin_code);
        if (is_single()) {
            for (size_t i = 0; i < numbers_.size(); i++) {
                int to_push;
                if (i % 2 != 0) {
                    to_push = numbers_.at(i) * 2;
                    to_push = resolve_bigger_ten(to_push);
                } else {
                    to_push = numbers_.at(i);
                }
                sum_numbers_.push_back(to_push);
            }
        } else {
            for (size_t i = 0; i < numbers_.size(); i++) {
                int to_push;
                if (i % 2 == 0) {
                    to_push = numbers_.at(i) * 2;
                    to_push = resolve_bigger_ten(to_push);
                } else {
                    to_push = numbers_.at(i);
                }
                sum_numbers_.push_back(to_push);
            }
        }

        return sum_values() % 10 == 0;
    }
};

int main() {
    Luhn a;

    cout << a.is_valid("2121") << endl;
    cout << a.is_valid("79927398713") << endl;
    cout << a.is_valid("1234") << endl;

    return 0;
}
