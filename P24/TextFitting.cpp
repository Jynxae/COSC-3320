#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<sstream>
using namespace std;

int fitText(int width, int length, vector<string> words)
{
    int repeat = 0;
    int currLength = length;
    int widthCounter = 1;

    //we will do tabulation
    for(int index = 0; index < words.size(); index++)
    {
      /*if words[index].size() < currLength
            currLength -= words[index].size()
             
          else
            widthCounter++;
            currLength = length;
            if(widthCounter > width)
            {
                return repeat;
            }

        if index + 1 == words.size
            index = -1;

             */
    }
    return repeat;
}

int main(){
    int width, height;
    vector<string> words;
    string word,line;
    ifstream fin("input1.txt");
    fin >> width;
    fin >> height;
    fin.ignore();
    getline(fin,line);
    istringstream iss(line);
    while(iss >> word)
    {
        words.push_back(word);
    }
    cout << fitText(width, height, words);
    return 0;
}