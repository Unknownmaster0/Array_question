#include <iostream>
#include <vector>
using namespace std;

// Problem link -> https://leetcode.com/problems/insert-interval/?envType=daily-question&envId=2024-03-17

// My own solution
// explanation link -> https://leetcode.com/problems/insert-interval/solutions/4891101/easy-solution-with-explanation/?envType=daily-question&envId=2024-03-17

// code ->
// t.c = O(n)

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
/* simple here -> all intervals are non-overlapping.
        But only interval can be overlap to any of the interval range or may not overlap;
        if new interval not overlap with any other interval, then bro, simply insert into last of ans
        else if it overlap, then check kha se kha tk overlap krega,
jb tk start of any interval not greater than newinterval start, then tb tk overlap krega.
*/
        int n = intervals.size();
        int nS = newInterval[0], nE = newInterval[1];
        vector<vector<int>> ans;
        int i=0;
        while(i<n && intervals[i][1] < nS){
            ans.push_back(intervals[i]);
            i++;
        }
        // now you got the overlapping.
        if(i < n){
            nS = min(nS, intervals[i][0]);
        }
        while(i < n && intervals[i][0] <= nE){
            nE = max(nE, intervals[i][1]);
            i++;
        }
        ans.push_back({nS, nE});

        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}