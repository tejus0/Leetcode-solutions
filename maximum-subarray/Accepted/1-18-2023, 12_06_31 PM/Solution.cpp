// https://leetcode.com/problems/maximum-subarray

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cs=0,mxs=INT_MIN;
        for(auto& i: nums){
            if(cs<0) cs=i;
            else cs+=i;
            mxs=max(cs,mxs);
        }
        return mxs;
    }
};