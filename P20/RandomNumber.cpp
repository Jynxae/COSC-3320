#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
using namespace std;

int mergeHelper(vector<int> subArray1, vector<int> subArray2)
{

/*

// this will be rachel and robert subarrays interchangably 
    // 3 ints, one to hold an index, one to hold a temp score, one to hold a final score. Start all at 0.
    while index < size of subArray2
        while score is less than array1 size AND array2[index] is more than array1[tempScore]
            increment score by one
        add tempScore to finalScore
        increment index
    return finalScore

*/
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

/*

// This function is VERY similar to mergeSort, I recommend writing a basic
    // mergeSort first, then adding the second array.

    find midpoint of left subarray
    find midpoint of right subarray

    create 4 subArrays (left & subarray for Robert and left & right for rachel)

    copy the data to each subarray (same as usual, just doing it twice, i used 2 separate for loops, one for left subarrays one for rights)

    // This is where knowing normal MergeSort helps in understanding
    create index values (i, j) for both robert and rachel (total of 4) set these to 0, then make 2 indexes to hold the parameter left (one for rob and one for rachel)
    
    if (i_indexRobert < leftSubArraySize And j_indexRobert < rightsubSize) // this could possibly be simplified if second condition is not needed
        add helper(leftRachelSubarray, rightRobertsubarray) to robertPoints
    repeat for rachel, make sure you swap the necessary objects/variables

    merge subarrays back into their respective arrays
    left and right robert will merge back into robertArray and vice versa.

    // the rest of the function is the same as basic mergeSort, with extra operations since thers two arrays,
    // you get the idea :)

*/

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
    int iRobert = 0, jRobert = 0, iRachel = 0, jRachel = 0, kRob = left, kRach = left;

    if(robArray[iRobert] < leftArrRob.size() && robArray[jRobert] < leftArrRob.size())
    {
        robPoints += mergeHelper(leftArrRach, rightArrRob); //to robertPoints
    }

    if(rachArray[iRachel] < leftArrRach.size() && rachArray[jRachel] < leftArrRach.size())
    {
        rachPoints += mergeHelper(leftArrRob, rightArrRach); //to rachelPoints
    }

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
        leftArrRach[kRach] = rightArrRach[jRachel];
        ++jRachel;
        ++kRach;
    }

}

void mergeSort(vector<int> array1, vector<int> array2, int left, int right, int robPoints, int rachPoints)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(array1, array2, left, mid, robPoints, rachPoints);
        mergeSort(array1, array2, mid + 1, right, robPoints, rachPoints);

        merge(array1, array2, left, mid, right, robPoints, rachPoints);
    }
}
int main()
{
    ifstream fin("input1.txt");
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