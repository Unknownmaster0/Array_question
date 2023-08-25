// question link -> https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
#include<iostream>
#include<vector>
using namespace std;

int findLengthOfLCIS(vector<int>& nums)
{
    
    int size = nums.size();
    if(size == 1)
        return 1;

    int start = 0, end = 0, maxLength = 1;

    for(int i = 1; i<size; i++)
    {
        // when the next element is greater then the previous element.
        if(nums[i] > nums[end])
        {
            end = i;
            maxLength = max(maxLength, end-start+1);
        }
        // when the next element is less than or equal to previous element.
        else{
            start = i, end = i;
        }
    }

    return maxLength;
}

int main()
{
    /*
    use these test cases.
    [2,2,2,2,2]
    [3,2,5,4,7,8,1]
    [1,2,3,2,4,5,7,8]
    [1,3,5,7]
    [1,3,2,4,1,5,3,7,6]
    [1,1,2]
    [1]
    */
    vector<int> v {1,3,5,4,7};
    cout<<"longest length of incresing sub-array is -> "<<findLengthOfLCIS(v)<<endl;
    return 0;
}