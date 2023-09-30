#include<iostream>
#include<fstream>
using namespace std;

void step(int low, int high)
{
    if(high <= low)
    {
        cout << high << " ";
    }
    else if (high <= 9)
    {
        cout << high << " ";
        step(low, high - 1);
    }
    else
    {
        int lastDigit = high % 10; // grab the last digit
        int divDigit = high / 10;
        if (abs(lastDigit - divDigit) == 1 || abs(divDigit - lastDigit == 1))
        {
            // recurse
            step(low, high - 1);
            cout<< high << " ";
        }
    }
}

int main(){
    ifstream fin("input1.tx3t");
    int low, high;
    fin >> low;
    fin.ignore();
    fin >> high;

    step(low, high);
    return 0;
}