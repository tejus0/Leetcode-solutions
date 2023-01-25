// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        vector<int>freq(k,0);
        int rem;
        int presum=0;
        for(int i=0;i<n;i++){
            presum +=(nums[i]%k+k)%k;
            //if(presum<0) presum += k;
            rem =presum % k;
            freq[rem]++;
            }
            int ans=freq[0];
            for(int i=0;i<k;i++){
                    ans += (freq[i]*(freq[i]-1))/2;
            }
        return ans;
    }
};