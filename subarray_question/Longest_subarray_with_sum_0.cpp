#include<iostream>
using namespace std;

#include <bits/stdc++.h>
#include <unordered_map>

int LongestSubsetWithZeroSum(vector < int > arr) {

    // optimal solution -> using mapping
    int maxLength = INT_MIN;
    unordered_map<int,int>m;

    int sum = 0;
    m[0] = -1;
    
    for(int i = 0; i<arr.size(); i++)
    {
        sum += arr[i];
        // if( m.find(sum) != m.end() )
        if(m.count(sum))
        {
            int index = i - m[sum];
            maxLength = max(maxLength, index);
        }
        else{
            m[sum] = i;
        }
    }

    if(maxLength == INT_MIN)
        return 0;

    return maxLength;


/*

  // Brutforce Approach
    int maxLength = INT_MIN;
    for(int i = 0; i<arr.size(); i++)
    {
        int sum = 0;
        for(int j = i; j<arr.size(); j++)
        {
            sum += arr[j];
            if(sum == 0)
            {
                maxLength = max(maxLength, j-i+1);
            }
        }
    }

    if(maxLength == INT_MIN)
        return 0;

    return maxLength;

    */
    

}


int main()
{
    
    return 0;
}