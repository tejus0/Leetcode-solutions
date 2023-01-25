// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:

    void rec(vector<vector<int>>& ans,vector<int>& comb, int k , int target, int num){
        if(k==0 and target==0){
            ans.push_back(comb);
            return;
        }
        if(k<0 or target<0){
            return;
        }
        if(num>9) return;

        comb.push_back(num);
        rec(ans,comb,k-1,target-num,num+1);
        comb.pop_back();
        rec(ans,comb,k,target,num+1);
    } 

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        vector<vector<int>> ans;
        rec(ans,comb,k,n,1);
        return ans;
    }
};