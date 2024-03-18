#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Problem link -> https://leetcode.com/problems/merge-intervals/description/

// Code ->
// t.c = O(n)
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> mergedAns;

        sort(intervals.begin(), intervals.end());
        for(auto itr:intervals){
            if(mergedAns.empty() || itr[0] > mergedAns.back()[1]){
                mergedAns.push_back({itr[0], itr[1]});
            }
            // we need to merge the intervals.
            else{
                // vector<int> prev = mergedAns.back();
/*as we are merging and pushing the new interval into the ans vector, thus we pop out the last interval.*/
                // mergedAns.pop_back();
/*start will remain same as that of previous start, as we have sorted on basis of start
so prev start will smaller than curr start.*/
                // mergedAns.push_back({prev[0], max(prev[1], itr[1])});

// either you write above three lines of code or just this single line.
                mergedAns.back()[1] = max(itr[1], mergedAns.back()[1]);
            }
        }

        return mergedAns;
    }
};

int main()
{

    return 0;
}