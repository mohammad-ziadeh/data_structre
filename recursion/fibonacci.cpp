#include <iostream>

using namespace std;

// 3

static int doFibonacci(const int number)
{
    if (number <= 1)
    {
        return number;
    }
    return doFibonacci(number - 1) + doFibonacci(number - 2);
}

int main()
{

    int iteration;
    cout << "Enter any number above 0:" << endl;
    cin >> iteration;

    if (iteration < 0)
    {
        cout << "The number should be bigger than 0" << endl;
    }
    else
    {
        for (int i = 0; i < iteration; i++)
        {
            cout << doFibonacci(i) << " ";
        }
    }

    return 0;
}