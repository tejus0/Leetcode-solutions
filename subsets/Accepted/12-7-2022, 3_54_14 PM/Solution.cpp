// https://leetcode.com/problems/subsets

class Solution {
public:

    void find_subset(vector<int>& nums,vector<int>&temp,int i, vector<vector<int>>&ans ){
        if(i==nums.size())
            ans.push_back(temp);
        else{
        //include
        temp.push_back(nums[i]);
        find_subset(nums,temp,i+1,ans);

        //exclude
        temp.pop_back();
        find_subset(nums,temp,i+1,ans);
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        find_subset(nums,temp,0,ans);
        return ans;
    }
};