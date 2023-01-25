// https://leetcode.com/problems/non-decreasing-subsequences

class Solution {
public:
    int n;
    vector<vector<int>> ans;
    
    void solve(int idx, vector<int>& a, vector<int> v){
        
        if(v.size()>1){
            ans.push_back(v);
        }
        
        map<int,int> m;
        for(int i = idx+1; i < n; ++i)
        {
            if((v.empty() or a[i]>= v.back()) and !m[a[i]]){
                m[a[i]] = 1;
                v.push_back(a[i]);
                solve(i, a, v);
                v.pop_back();
            }
        }   
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        solve(-1, nums, v);
        return ans;
    }
};