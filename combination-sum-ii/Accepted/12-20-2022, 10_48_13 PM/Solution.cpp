// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> result;
    
    void sum2(vector<int> &curr, int target, int sum, vector<int> &candidates, int ind, int n){
        if(target == sum){
            result.push_back(curr);
            return;
        }
        else if(sum>target){
            return;
        }
        
        for(int i = ind; i < n; i++){
            if(i > ind && candidates[i]==candidates[i-1])               //to avoid picking up the same combnations i.e. we don't pick same element for certain kth position of a combination 
                continue;
            sum += candidates[i];
            curr.push_back(candidates[i]);
            sum2(curr, target, sum, candidates, i+1, n);
            sum -= candidates[i];
            curr.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        sum2(curr, target, 0, candidates, 0, n);
        return result;
    }
};