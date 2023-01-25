// https://leetcode.com/problems/combination-sum

class Solution {
public:
    
    void rec(int tgt,vector<int>& arr,int ind,vector<vector<int>>& ans,vector<int>& temp){
        if(ind==arr.size()){
            if(tgt==0)
                ans.push_back(temp);
            return;
        }
        if(arr[ind]<=tgt){
            temp.push_back(arr[ind]);
            rec(tgt-arr[ind],arr,ind,ans,temp);
            temp.pop_back();
        }
        rec(tgt,arr,ind+1,ans,temp);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        rec(target,candidates,0,ans,temp);
        return ans;
    }
};