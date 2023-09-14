#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<sstream>
using namespace std;

bool divideArray(vector<int> &input, int k, int index)
{
    if(input.empty())//if vector is empty then we successfully went through the whole list
    {
        return true;
    }

    int curr = input.front();   //delete the vector at the beginning one by one
    input.erase(input.begin());

    for (int i = 0; i < k-1; i++) //we repeat this for each size k is 
    {
        auto next = curr + 1;   //sets for concurrent value
        auto conc = find(input.begin(), input.end(), next); //looks for concurrent value
        if (conc != input.end())    //if it finds the concurrent value, then we can delete the current spot and go next
        {
            input.erase(conc);
            curr = next;
        }
        else
        {
            return false; //returns false if there is no concurrent value
        }
    }

    //instead of splitting the array, how about we change where we start at the index each time
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