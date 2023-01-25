// https://leetcode.com/problems/permutations

class Solution {
public:

    void all_rec(vector<int>& nums,vector<vector<int>> &ans, vector<int>& curr_per,int flag[]){
        if(curr_per.size()==nums.size()){
            ans.push_back(curr_per);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!flag[i]){
                curr_per.push_back(nums[i]);
                flag[i]=1;
                all_rec(nums,ans,curr_per,flag);
                flag[i]=0;
                curr_per.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr_per;
        int flag[nums.size()];
        for(int i=0;i<nums.size();i++){
            flag[i]=0;
        }
        all_rec(nums, ans,curr_per,flag);
        return ans;
    }
};