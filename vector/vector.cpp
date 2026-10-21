#include <iostream>
using namespace std;


class CustomVector {
private:
    CustomVector* nextItemAddress = nullptr;
public:
    static CustomVector* currentItemAddress;
    int value;

    void setNextAddress(CustomVector*);

    CustomVector(int);
};

static CustomVector* headAddress = nullptr;

CustomVector::CustomVector(const int val) {
    value = val;
}

CustomVector* CustomVector::currentItemAddress = nullptr;

void CustomVector::setNextAddress(CustomVector* nextAdd) {
    nextItemAddress = nextAdd;
}



int main() {

CustomVector item1(4);
headAddress = &item1;
    return 0;
}
