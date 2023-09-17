#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

int lastRemaining(int num)
{
    if(num == 1)
    {
        return 1;
    }

    if(num % 2 == 0)
    {
        return lastRemaining(num / 2);
    }

    else
    {
        return 2 * lastRemaining(num / 2);
    }
}

int main()
{
    int input;
    bool onlyOne = false;
    cin >> input;
    cout << lastRemaining(input);
    return 0;
}