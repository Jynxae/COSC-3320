#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include<fstream>

using namespace std;

//c6e85239-b552-4f6b-bf2a-6839d3ed81e0

bool isValidAssignment(const string &string1, const string &string2, const string &target, const unordered_map<char, char> &symbol_to_digit)
{
    int num1 = 0, num2 = 0, result = 0;

    for (char c : string1)
    {
        num1 = num1 * 10 + (symbol_to_digit.at(c) - '0');
    }

    for (char c : string2)
    {
        num2 = num2 * 10 + (symbol_to_digit.at(c) - '0');
    }

    for (char c : target)
    {
        result = result * 10 + (symbol_to_digit.at(c) - '0');
    }

    return num1 + num2 == result;
}

bool backTrack(int index, const string &symbols, const string &string1, const string &string2, const string &target, unordered_map<char, char> &symbol_to_digit, vector<bool> &used_digits)
{
    if (index == symbols.size())
    {
        if (isValidAssignment(string1, string2, target, symbol_to_digit))
        {
            return true;
        }
        return false;
    }

    for (char digit = '0'; digit <= '9'; ++digit)
    {
        if (!used_digits[digit - '0'])
        {
            symbol_to_digit[symbols[index]] = digit;
            used_digits[digit - '0'] = true;

            if (backTrack(index + 1, symbols, string1, string2, target, symbol_to_digit, used_digits))
            {
                return true;
            }

            used_digits[digit - '0'] = false;
        }
    }

    return false;
}

string solveSymbols(const string &symbols, const string &string1, const string &string2, const string &target)
{
    unordered_map<char, char> symbol_to_digit;
    vector<bool> used_digits(10, false); // To keep track of used digits (0-9)

    if (backTrack(0, symbols, string1, string2, target, symbol_to_digit, used_digits))
    {
        string result;
        for (char c : symbols)
        {
            result += symbol_to_digit[c];
        }
        return result;
    }

    return nullptr;
}

int main()
{
    ifstream fin("input1.txt");
    string symbols, string1, string2, target;

    fin >> symbols;

    fin >> string1;

    fin >> string2;

    fin >> target;

    string output = solveSymbols(symbols, string1, string2, target);
    cout << output << endl;

    return 0;
}
