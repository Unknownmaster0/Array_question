#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_set>
using namespace std;

    unordered_set<string> st;
    void solve(vector<int>& arr, int n, vector<vector<int>>& ans, vector<int>&temp, vector<bool>&used)
    {
        if(temp.size() == n){
            string s = "";
            for(auto it:temp){
                s += to_string(it);
            }
            if(st.find(s) == st.end()){
                ans.push_back(temp);
                st.insert(s);
            }
            return;
        }
        
        for(int i = 0; i<n; i++){
            if(used[i] == false){
                temp.push_back(arr[i]);
                used[i] = true;
                
                solve(arr, n, ans, temp, used);
                
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> store;
        vector<int> temp;
        vector<bool>used(n,0);
        solve(arr, n, store,temp, used);
        
        return store;
    }

void print(vector<vector<int>> ans){
    for(auto itr:ans){
        for(auto it:itr){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vector<int> arr = {1,2,1};
    int size = 3;
    vector<vector<int>> ans = uniquePerms(arr, size);
    print(ans);
    return 0;
}