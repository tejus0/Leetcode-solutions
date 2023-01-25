// https://leetcode.com/problems/permutations

class Solution {
public:

    void all_rec(vector<int>& nums,vector<vector<int>> &ans, int curr){
        if(curr==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=curr;i<nums.size();i++){
                swap(nums[i],nums[curr]);
                all_rec(nums,ans,curr+1);
                swap(nums[i],nums[curr]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        all_rec(nums, ans,0);
        return ans;
    }
};