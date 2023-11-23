#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

// question link -> https://leetcode.com/problems/arithmetic-subarrays/solutions/4320140/nice-solution-with-the-two-approach-brutforce-and-the-optimal-one-also/
// understanding link -> https://www.youtube.com/watch?v=Zul5uok4IpQ

/*
// ************** BRTUFORCE APPROACH ***************************

// bool checkArithmetic(vector<int> temp){
//     sort(temp.begin(), temp.end());
//     // check if there is any element who is not following the condition for the arithmetic.
//     int diff = temp[1]-temp[0];
//     int size = temp.size();
//     for(int i = 2; i<size; i++){
//         int difference = temp[i] - temp[i-1];
//         if(difference != diff)
//              return false;
//     }
//     return true;
// }

vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
    vector<bool> ans;

    for(int i = 0; i<l.size(); i++){
        vector<int> temp(nums.begin()+l[i], nums.begin()+r[i]);
        // call for check arithmetic function.
        bool check = checkArithmetic(temp);
        ans.push_back(check);
    }
    return ans;
}
*/

/************* optimal approach ******************/
/* Concept -> Just no need to create the copy of the original array of the size l[0] to r[0]

NOw, in this approach we just focus on the concept of the AP, that
a, a+d, a+2d ........., a+(n-1)d [where n is the length of the array]
step 1 -> call the checkArithmetic function with the parameters
step 2 -> then in the function, find the max and the min element and
        also store the element of the subarray in some data
structure say(map or set)
step 3 -> find the length - 1 of the subarray
step 4 -> do focus here (maximum element is the last element of the ap
and the minimum element is first element of the ap)
then do = (maxi - mini) / length
this will give you the 'd' of the ap
if the do thing in above is not completely divisible then not
an ap , return false;
step 5 -> traverse the map by adding the d to the minimum element
and finding the element in the map, if any element is not found
return false;
*/
bool checkArithmetic(vector<int> nums, int s, int e)
{
    // find the max and min in the range of s and e;
    int maxi = INT_MIN;
    int mini = INT_MAX;
    unordered_map<int, int> st;
    for (int i = s; i <= e; i++)
    {
        maxi = max(maxi, nums[i]);
        mini = min(mini, nums[i]);
        st[nums[i]]++;
    }

    // actual length is e-s+1, but we need to take the length-1, thus I don't add the 1.
    int length = e - s;
    if ((maxi - mini) % length)
        return false;

    // maxi = a + (n-1)d
    // mini = a
    // length = n-1
    int d = (maxi - mini) / length;
    // now push the element into the set and check if it present afte adding the common difference to the first element of nums[s]
    int first = mini;
    while (first != maxi)
    {
        first += d;
        if (st.find(first) == st.end())
            return false;
    }
    return true;
}

vector<bool> checkArithmeticSubarrays(vector<int> &nums, vector<int> &l, vector<int> &r)
{
    vector<bool> ans;
    for (int i = 0; i < l.size(); i++)
    {
        bool check = checkArithmetic(nums, l[i], r[i]);
        ans.push_back(check);
    }
    return ans;
}

int main()
{

    return 0;
}