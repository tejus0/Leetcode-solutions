// https://leetcode.com/problems/subsets-ii

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;       //to store all susbets
        bool prev;
        vector<int> curr;         //to store current individual subset (that we will build)
        sort(nums.begin(),nums.end());      //sort the array so that duplicates are adjacent 
        helper(nums,curr,0,ans,false);       //we start from index 0
        return ans;
        
    }
    
   void helper(vector<int>& nums,vector<int>&temp,int i, vector<vector<int>>&ans, bool prev ){
        if(i==nums.size())
            ans.push_back(temp);
        else{
        helper(nums,temp,i+1,ans,false);
        //include
        if(i>0 and nums[i]==nums[i-1] and (!prev)) return;
        temp.push_back(nums[i]);
        helper(nums,temp,i+1,ans,true);

        //exclude
        temp.pop_back();
        
        }
    }  
};