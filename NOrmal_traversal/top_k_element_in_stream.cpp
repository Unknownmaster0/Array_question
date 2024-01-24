#include<iostream>
#include<vector>
#include<set>
#include<map>
using namespace std;

    vector<vector<int>> kTop(vector<int>& arr, int N, int K) {
        vector<vector<int>> ans;
        vector<int> store;
        
        map<int,int> freq;
        set<pair<int,int>> st;
        
        for(int i = 0; i<N; i++){
            
// first check if the freq of the curr element is already present in the set. if yes, then erase it from the set
            if(freq[arr[i]] > 0) st.erase({-freq[arr[i]],arr[i]});
            
            freq[arr[i]]++;
            
            st.insert({-freq[arr[i]], arr[i]});
            
            int total = K;
            for(auto itr:st){
                if(total == 0) break;
                store.push_back(itr.second);
                total--;
            }
            
            ans.push_back(store);
            store.clear();
        }
        
        return ans;
    }

int main()
{
    
    return 0;
}