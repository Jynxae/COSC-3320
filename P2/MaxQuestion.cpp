#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

int maxProfit(vector<int>& prices)
    {
        int maxdiff = 0;
        for (int x = 0; x < prices.size(); x++) // goes through each day
        {
            for (int y = x; y < prices.size(); y++) // for each day, it goes through the price
            {
                maxdiff = max(maxdiff, prices.at(y) - prices.at(x));
            }
        }
        return maxdiff;
    }

int main()
{
    ifstream fin("input1.txt");
    int size = 0;
    int num = 0;
    fin >> size;
    fin.ignore();
    vector<int> input;
    for(int x = 0; x < size; x++)
    {
        fin >> num;
        input.push_back(num);
    }

    cout << maxProfit(input);

    return 0;
}
