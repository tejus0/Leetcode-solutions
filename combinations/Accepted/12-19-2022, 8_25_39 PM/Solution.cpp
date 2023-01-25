// https://leetcode.com/problems/combinations

class Solution {
public:

    void find_combo(int start, int n,vector<vector<int>>&ans, vector<int>& curr , int k){
        if(curr.size()==k){
            ans.push_back(curr);
            return;
        }
        for(int i=start;i<=n;i++){
            curr.push_back(i);
            find_combo(i+1,n,ans,curr,k);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;
        find_combo(1,n,ans,curr,k);
        return ans;
    }
};