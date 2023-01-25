// https://leetcode.com/problems/subarray-sum-equals-k

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int,int> freq;
        int sum=0,count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k) count++;
            else if(freq.find(sum-k)!=freq.end()){
                count+=freq[sum-k];
            }
            freq[sum]++;
            
        }
        return count;
    }
};