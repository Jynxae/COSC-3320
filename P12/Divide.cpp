#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;

bool divideArray(vector<int> input, int k)
{
    //check size of input vector, if zero then return
    if(input.size() == 0 )
    {
        cout << "true" << endl;
        return true;
    }

    //only grabs k values from the beginning. Avoids having repeat values if necessary
    vector<int> tempArray;
    for(int x = 0; x <= k; x++)
    {
        if(input.size() - 1 == x)
        {
            tempArray.push_back(input.at(x));
            input.erase(input.begin() + x);
            break;
        }
        if(input.at(x) != input.at(x+1))
        {
            tempArray.push_back(input.at(x));
            input.erase(input.begin() + x);
            x--;
        }
        if(tempArray.size() == k)
        {
            break;
        }
    }

    //if there are any values left in input and tempArray isn't at max size, push the rest of input into tempArray
    if(tempArray.size() < k && !input.empty())
    {
        for(int x = 0; x < input.size(); x++)
        {
            tempArray.push_back(input.at(x));
        }
        sort(tempArray.begin(), tempArray.end());
    }

    //Go through tempArray to see if it passes.
    for(int x = 0; x < tempArray.size(); x++)
    {
        if(tempArray.size() - 1 == x)
        {
            break;
        }
        if(tempArray.at(x) == tempArray.at(x+1))
        {
            cout << "false" << endl;
            return false;
        }
    }

    //call the function again and pass whatever is remaining in input vector.
    divideArray(input, k);
}

void divide(vector<int> input, int posInt)
{
    if(input.size() % posInt != 0)
    {
        cout << "false" << endl;
        return;
    }
    sort(input.begin(), input.end());

    divideArray(input, posInt);
    
}

int main(){

    ifstream fin("input1.txt");
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