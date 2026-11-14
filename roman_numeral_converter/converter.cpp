#include <iostream>
#include <vector>
using namespace std;

class roman_num {
    const vector<int> values_ = {
        1000, 900, 500, 400, 100, 90,
        50, 40, 10, 9, 5, 4, 1
    };

    const vector<string> symbols_ = {
        "M", "CM", "D", "CD", "C", "XC",
        "L", "XL", "X", "IX", "V", "IV", "I"
    };

public:
    void convert(int num) const {
        for (int i = 0; i < values_.size(); ++i) {
            while (num >= values_[i]) {
                num -= values_[i];
                cout << symbols_[i];
            }
        }
    }
};


int main() {
    roman_num a;
    a.convert(3459);
    return 0;
}
