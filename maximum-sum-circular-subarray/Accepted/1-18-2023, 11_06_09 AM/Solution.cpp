// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution {
    int Kadane(vector<int>& nums){    
        int mxsum=nums[0],cs=nums[0];
        for(auto i=1;i<nums.size();i++){
            cs += nums[i];
            if(cs<nums[i]) cs=nums[i];
            mxsum=max(cs,mxsum); 
        }
        return mxsum;
    }
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int total=0;
        int origmax=Kadane(nums);
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            nums[i]= nums[i]*-1;            
        }
        int minsum=Kadane(nums);
        if(minsum+total==0) return origmax;
        return max(total+minsum,origmax);
    }
};