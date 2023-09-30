#include<iostream>
#include<fstream>
using namespace std;

void step(int low, int high)
{
    if(high <= low)
    {
        cout << high << " ";
    }
    int reamingNumber = high;
    int lastDigit = 0;  //grab the last digit
    while(reamingNumber > 0)
    {
        lastDigit = reamingNumber % 10;
        reamingNumber /= 10;
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