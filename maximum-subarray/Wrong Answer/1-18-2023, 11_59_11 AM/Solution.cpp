// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,mxs=0;
        for(auto i: nums){
            cs+=i;
            if(cs<0) cs=0;
            mxs=max(cs,mxs);
        }
        return mxs;
    }
};