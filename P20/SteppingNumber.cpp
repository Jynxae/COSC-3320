#include<iostream>
#include<fstream>
using namespace std;

void step(int low, int high)
{
    if(high <= low)
    {
        if (high <= 9)
        {
            cout << high << " ";
        }
        return;
    }
    else if (high <= 9)
    {
        step(low, high - 1);
        cout << high << " ";
    }
    else
    {
        int lastDigit = high % 10; // grab the last digit
        int divDigit = high / 10; //everything left side of the digit
        bool stepping = true;
        while(divDigit > 9)
        {
            if(abs((divDigit % 10) - lastDigit) != 1 || abs(lastDigit - (divDigit % 10)) != 1)
            {
                stepping = false;
                break;
            }
            lastDigit = divDigit % 10;
            divDigit /= 10;
        }
        
        if ((abs(lastDigit - divDigit) == 1 || abs(divDigit - lastDigit == 1)) && stepping == true)
        {
            // recurse
            step(low, high - 1);
            cout<< high << " ";
        }
        else{
            step(low, high - 1);
        }
    }
}

int main(){
    ifstream fin("input1.txt");
    int low, high;
    fin >> low;
    fin.ignore();
    fin >> high;

    step(low, high);
    return 0;
}