#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// problem link -> https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=daily-question&envId=2024-03-18

// code -> 
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
// this question is same as 56.merge Interval of the leetcode, check that out.

// you need to simply merge the overlapping interval, but with shuttle change bro.
// change is this time start = max(curr start, new start)
//                      end = min(curr end, new end)
        sort(points.begin(), points.end());
        vector<int> temp;
        temp = points[0];
        int length = 1;
        for(auto itr:points){
            // new start = itr[0], new end = itr[1]
            if(itr[0] <= temp[1]){
                // overlapping, then simply merge them.
                temp[0] = max(temp[0], itr[0]); // updating start
                temp[1] = min(temp[1], itr[1]); // updating end
            }
            else{
                // non-overlapping then simply push into the ans
                temp = itr;
                length ++;
            }
        }

        return length;
    }
};

int main()
{
    
    return 0;
}