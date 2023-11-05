#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

void print(vector<int> ans)
{
    for (auto i : ans)
        cout << i << " ";
    cout << endl;
}

vector<int> topK(vector<int> &nums, int k)
{
    // Code here
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
        mp[nums[i]] += 1;

    vector<pair<int, int>> v;
    for (auto x : mp)
        v.push_back(make_pair(x.second, x.first));

    sort(v.rbegin(), v.rend());

    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.push_back(v[i].second);
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 3, 3, 4};

    vector<int> ans = topK(nums, 2);

    cout << "the top frequency elements of the array is -> " << endl;
    print(ans);
    return 0;
}