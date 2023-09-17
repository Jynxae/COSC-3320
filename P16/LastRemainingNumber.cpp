#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

int lastRemaining(int num, bool switchSides)
{
    if(num == 1)
    {
        return 1;
    }

    return (num % 2 == 1 || switchSides) ? 2 * lastRemaining(num / 2, !switchSides) : 2 * lastRemaining(num / 2, !switchSides) - 1;
    //ternary practice
    // ^here we put in our if statement
    //                              ? signifies what we will do             : is the options we will do
}

int main()
{
    int input;
    bool onlyOne = true;
    cin >> input;
    cout << lastRemaining(input, onlyOne);
    return 0;
}