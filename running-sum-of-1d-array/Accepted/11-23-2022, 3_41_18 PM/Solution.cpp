// https://leetcode.com/problems/running-sum-of-1d-array

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> ans;
        long sum=0;
        for(auto it: nums){
            sum+=it;
            ans.push_back(sum);
        }
        return ans;
    }
};