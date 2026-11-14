#include <iostream>
#include <map>
using namespace std;

class anagram {
    map<char, int> characters_;

    void string_breaker(const string &word) {
        characters_.clear();
        for (char ch: word) {
            characters_[ch]++;
        }
    }

public:
    bool are_same(const string &a, const string &b) {
        if (a.length() != b.length()) {
            return false;
        }
        string_breaker(b);
        for (char ch: a) {
            auto found_char = characters_.find(ch);
            if (found_char == characters_.end() || found_char->second == 0) {
                return false;
            }
            found_char->second--;
        }
        return true;
    }
};

int main() {
    anagram a;
    cout << a.are_same("listen", "silent") << '\n'; // true
    cout << a.are_same("hello", "hlllo") << '\n'; // false
    cout << a.are_same("aab", "abb") << '\n'; // false

    return 0;
}
