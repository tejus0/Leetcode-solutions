// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
            vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int curr=nums[i];
            int target=-curr;
            int s=i+1;
            int e=n-1;
            while(s<e){
                if(nums[s]+nums[e]==target){
                    ans.push_back({nums[i],nums[s],nums[e]});
                    s++,e--;
                    while(s<e and nums[i]==nums[s]) s++;
                    while(s<e and nums[i]==nums[e]) e--;
                }
                else if(nums[s]+nums[e]>target){
                    e--;
                }
                else s++;
            }
            while(nums[i]==nums[i+1]) i++;
        }
        return ans;
    }
};