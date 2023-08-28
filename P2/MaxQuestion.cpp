#include <iostream>
#include <vector>
#include<fstream>
using namespace std;

int maxProfit(vector<int>& prices)
    {
        int price = 0;
        for (int x = 0; x < prices.size(); x++) // goes through each day
        {
            for (int y = x; y < prices.size(); y++) // for each day, it goes through the price
            {
                int total = prices.at(y) - prices.at(x);
                if (total > price)
                {
                    price = total;
                }
            }
        }
        return price;
    }

int main()
{
    int size = 0;
    int num = 0;
    cout << "Reem is here " << endl;
    cin >> size;
    cout << size+1 << endl;
    // cin.ignore();
    vector<int> input;
    // for(int x = 0; x < size; x++)
    // {
    //     cin >> num;
    //     input.push_back(num);
    // }

    return 0;
}
