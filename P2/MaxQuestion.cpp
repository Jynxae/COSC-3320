#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

int maxProfit(vector<int>& prices)
    {
        int left = 0; 
        int right = 1;
        int maxi = 0;
        
        while (right < prices.size())
        {
            if(prices.at(left) < prices.at(right))
            {
                int currMax = prices.at(right) - prices.at(left);
                maxi = max(maxi, currMax);
            }
            else{
                left = right;
            }
            right += 1;
        }
        return maxi;
        // int maxdiff = 0;
        // for (int x = 0; x < prices.size(); x++) // goes through each day
        // {
        //     for (int y = x; y < prices.size(); y++) // for each day, it goes through the price
        //     {
        //         int currMax = prices.at(y) - prices.at(x);
        //         maxdiff = max(maxdiff, currMax);
        //     }
        // }
        // return maxdiff;
    }

int main()
{
    ifstream fin("input2.txt");
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
