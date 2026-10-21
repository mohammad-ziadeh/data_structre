#include <iostream>

using namespace std;

// 3

static int getSum(const int num)
{
    if (num <= 0)
    {
        return num;
    }
    return num + getSum(num - 1);
}

int main()
{
    int number;

    cout << "Enter any number above 0:" << endl;
    cin >> number;

    if (number < 0)
    {
        cout << "The number should be bigger than 0" << endl;
    }
    else
    {
        cout << getSum(number);
    }

    return 0;
}