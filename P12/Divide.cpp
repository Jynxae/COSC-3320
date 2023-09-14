#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;

bool divideArray(vector<int> &input, int k, int index)
{
    //check size of input vector, if zero then return
    if(input.empty())
    {
        return true;
    }

    int firstIndex = input.at(0);
    input.erase(input.begin());

    for (int i = index + 1; i < index + k; i++)
    {
        auto conc = find(input.begin(), input.end(), ++firstIndex);
        if (conc != input.end())
            input.erase(conc);
        else
            return false;
    }

    // call the function again and pass whatever is remaining in input vector.
    return divideArray(input, k, index + k);
}

void divide(vector<int> input, int k)
{
    if(input.size() % k != 0)
    {
        cout << "false" << endl;
        return;
    }
    sort(input.begin(), input.end());
    int index = 0;
    bool res = divideArray(input, k, index);
    if(res)
    {
        cout << "true";
    }
    else{
        cout << "false";
    }

}

int main(){

    ifstream fin("input3.txt");
    vector<int> in;
    int value;
    int k;

    string lineOfNums = "";
    getline(fin,lineOfNums);
    istringstream iss(lineOfNums);

    while(iss >> value)
    {
        in.push_back(value);
    }

    fin >> k;

    /*for(int x = 0; x < in.size(); x++)
    {
        cout << in.at(x) << " ";
    }
    cout << endl;
    cout << "K: " << endl;*/

    divide(in, k);

    return 0;
}