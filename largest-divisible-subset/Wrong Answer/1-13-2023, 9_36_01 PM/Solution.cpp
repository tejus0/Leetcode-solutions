// https://leetcode.com/problems/largest-divisible-subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n= nums.size();
        //sort(nums.begin(),nums.end());
        int max=1;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    if(max<dp[i]) max=dp[i];
                }
            }
        }
        int prev=-1;
        vector<int> ans;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==max and (prev%nums[i]==0 || prev==-1)){
                ans.push_back(nums[i]);
                max--;
                prev=nums[i];
            }
        }
        return ans;
    }
};