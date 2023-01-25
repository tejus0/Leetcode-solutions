// https://leetcode.com/problems/permutations-ii

class Solution {
public:
     void all_rec(vector<int>& nums,vector<vector<int>> &ans, int curr){
        if(curr==nums.size()){
            ans.push_back(nums);
            return;
        }
        set<int> mp;
        for(int i=curr;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()) continue;
                mp.insert(nums[i]);
                swap(nums[i],nums[curr]);
                all_rec(nums,ans,curr+1);
                swap(nums[i],nums[curr]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        all_rec(nums,ans,0);
        return ans;
    }
};