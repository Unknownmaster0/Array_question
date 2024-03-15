#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15

// code ->

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
/*
// Method 1 -> using the prfix and suffix array.    t.c = O(n)  || s.c = O(n)
        vector<int> prefix(n, 0);
        vector<int> suffix(n, 0);
        vector<int> ans; // for storing the answer.
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] * nums[i];
            suffix[n-1-i] = suffix[n-i] * nums[n-1-i];
        }

        for(int i=0; i<n; i++){
            if(i==0){
                ans.push_back(suffix[i+1]);
            }
            else if(i == n-1){
                ans.push_back(prefix[i-1]);
            }
            else{
                ans.push_back(prefix[i-1] * suffix[i+1]);
            }
        }
*/

// t.c = O(n)   ||  s.c = O(n)
// Method 2 -> IN this we are just first taking number from the left of the array, 
            // then taking number from right of the array.
// ans[i] = left numbers product * right numbers product (except the number itself.)
        vector<int> ans;
        int left = 1, right = 1;

// left numbers product
        for(int i=0; i<n; i++){
            ans.push_back(left);
            left *= nums[i];
        }
// right numbers product
        for(int i=n-1; i>=0; i--){
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};


int main()
{

    return 0;
}