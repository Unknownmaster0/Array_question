#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// question link -> https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/?envType=daily-question&envId=2023-11-04

/*
    concept -> 
    As both the Ant can move in both the direction, but ignore the question line that when two ant come at same index of plank, then they change the direction.

    Simple concept -> Find the maximum time taken by the ant of the left array and similarly for the right array.
                    Then again find the maximum of the both. -> Required Ans.


    For finding the max in the left part -> ant current index on the plank.
    For right -> It is  (size of plank - ant current index).
*/

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
/*
Forget about the case when the ant change the direction of itself.
As, it is not mention in the question that, we need to find the name of element
who fall last.
*/
    int leftMaxi = INT_MIN;
    int rightMaxi = INT_MIN;

// find the max time taken ant in the left array.
    for(int i = 0; i<left.size(); i++)
        leftMaxi = max(leftMaxi, left[i]);

// find the max time taken by ant in right array.
    for(int i = 0; i<right.size(); i++)
        rightMaxi = max(rightMaxi, n-right[i]);

    return max(leftMaxi, rightMaxi);
}

int main()
{
    vector<int> left = {4,3};
    vector<int> right = {0,1};

    int sizeOfPlank = 4;

    cout<<"the maximum time taken to fall is -> "<<getLastMoment(sizeOfPlank,left,right);
    return 0;
}