// https://leetcode.com/problems/find-the-duplicate-number

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ans;
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=mp[nums[i]]+1;
        }
        for(auto it: mp){
            if(it.second>1){
                ans=it.second;
            }
        }
        return ans;
    }
};