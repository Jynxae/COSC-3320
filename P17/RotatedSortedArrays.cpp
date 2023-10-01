#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

//658bbf66-2104-4e8f-8f38-4bfdb6682780

int pivotIndex(vector<int> arr, int target)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (target == arr[mid])
        {
            return mid;
        }

        // left sorted portion
        if (arr[left] <= arr[mid])
        {
            if (target > arr[mid] || target < arr[left])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        // right sorted portion
        else
        {
            if (target < arr[mid] || target > arr[right])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
    }

    return -1;
}

int findK(vector<int> arr)
{
    int left = 0;
    int right = arr.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > arr[right])
        {
            // The rotation point is in the right half
            left = mid + 1;
        }
        else
        {
            // The rotation point is in the left half
            right = mid;
        }
    }

    // left now points to the rotation point
    return left;
}

int main()
{
    ifstream fin("input1.txt");
    string line;
    vector<int> arr;
    getline(fin, line);
    stringstream ss(line);
    int num, target;

    while (ss >> num)
    {
        arr.push_back(num);
    }
    fin >> target;

    cout << findK(arr) << '\n';
    cout << pivotIndex(arr, target);

    return 0;
}

