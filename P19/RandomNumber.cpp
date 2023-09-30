#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

int mergeHelper(vector<int> subArray1, vector<int> subArray2)
{
    int index = 0;
    int tempScore = 0;
    int finalScore = 0;
    while(index < subArray2.size())
    {
        while(tempScore < subArray1.size() && subArray2.at(index) > subArray1.at(tempScore))
        {
            tempScore++;
        }
        finalScore += tempScore;
        index++;
    }
    return finalScore;

}

void merge(vector<int> &robArray, vector<int> &rachArray, int left, int mid, int right, int &robPoints, int &rachPoints)
{

    int n1 = mid - left + 1;    //find midpoint of left subarray
    int n2 = right - mid;       //find midpoint of right subarray

    vector<int> leftArrRob(n1);     //create 4 subarrays
    vector<int> leftArrRach(n1);
    vector<int> rightArrRob(n2);
    vector<int> rightArrRach(n2);

    for (int i = 0; i < n1; ++i)                //copy data to each subarray
    {
        leftArrRob[i] = robArray[left + i];
        leftArrRach[i] = rachArray[left + i];
    }
    for (int j = 0; j < n2; ++j)
    {
        rightArrRob[j] = robArray[mid + 1 + j];
        rightArrRach[j] = rachArray[mid + 1 + j];
    }


    int iRobert = 0, jRobert = 0, iRachel = 0, jRachel = 0;
    int kRob = left, kRach = left;


    if(iRobert < leftArrRob.size() && jRobert < rightArrRob.size())
    {
        robPoints += mergeHelper(leftArrRach, rightArrRob); //to robertPoints
        iRobert++;
    }

    if(iRachel < leftArrRach.size() && jRachel < rightArrRach.size())
    {
        rachPoints += mergeHelper(leftArrRob, rightArrRach); //to rachelPoints
        iRachel++;
    }

    iRobert = 0, jRobert = 0, iRachel = 0, jRachel = 0;
    kRob = left;
    kRach = left;

    //roberts merge
    while (iRobert < n1 && jRobert < n2) {          //merge sub two arrays
        if (leftArrRob[iRobert] <= rightArrRob[jRobert]) {
            robArray[kRob] = leftArrRob[iRobert];
            ++iRobert;
        } else {
            robArray[kRob] = rightArrRob[jRobert];
            ++jRobert;
        }
        ++kRob;
    }

    while (iRobert < n1) {        // Copy the remaining elements of leftArr[], if any
        robArray[kRob] = leftArrRob[iRobert];
        ++iRobert;
        ++kRob;
    }

    while (jRobert < n2) {        // Copy the remaining elements of rightArr[], if any
        robArray[kRob] = rightArrRob[jRobert];
        ++jRobert;
        ++kRob;
    }

    //rachels merge
    while (iRachel < n1 && jRachel < n2) {          //merge sub two arrays
        if (leftArrRach[iRachel] <= rightArrRach[jRachel]) {
            rachArray[kRach] = leftArrRach[iRachel];
            ++iRachel;
        } else {
            rachArray[kRach] = rightArrRach[jRachel];
            ++jRachel;
        }
        ++kRach;
    }

    while (iRachel < n1) {        // Copy the remaining elements of leftArr[], if any
        rachArray[kRach] = leftArrRach[iRachel];
        ++iRachel;
        ++kRach;
    }

    while (jRachel < n2) {        // Copy the remaining elements of rightArr[], if any
        rachArray[kRach] = rightArrRach[jRachel];
        ++jRachel;
        ++kRach;
    }

}

void mergeSort(vector<int> &array1, vector<int> &array2, int left, int right, int &robPoints, int &rachPoints)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array1, array2, left, mid, robPoints, rachPoints);    //grab left side of the array
        mergeSort(array1, array2, mid + 1, right, robPoints, rachPoints); //grab right side of the array

        merge(array1, array2, left, mid, right, robPoints, rachPoints);
    }
}
int main()
{
    ifstream fin("input3.txt");
    vector<int> robert;
    vector<int> rachel;
    int value;
    int robPoints = 0;
    int rachPoints = 0;
    string line;
    getline(fin,line);
    stringstream ss(line);

    while(ss >> value)
    {
        robert.push_back(value);
    }

    getline(fin, line);
    stringstream sss(line);
    while(sss >> value)
    {
        rachel.push_back(value);
    }

    mergeSort(robert,rachel,0,robert.size()-1, robPoints, rachPoints);
    cout << robPoints << " " << rachPoints;

    return 0;
}