// https://leetcode.com/problems/first-missing-positive

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int current=nums[i];
            if(nums[i]>0 && nums[i]<=n){
                if(nums[nums[i]-1]!=nums[i]){
                    swap(nums[nums[i]-1],nums[i]);
                    i--;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            int current=nums[i];
            if(current!=i+1){
                return i+1;
            }
        }
        return n+1;
    }
};