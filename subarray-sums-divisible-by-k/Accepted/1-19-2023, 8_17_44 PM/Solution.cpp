// https://leetcode.com/problems/subarray-sums-divisible-by-k

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n= nums.size();
        map<int,int> freq;
        freq.insert({0,1});
        int ans=0;
        int cum_sum=0;
        for(int i=0;i<n;i++){
            cum_sum +=nums[i];
            int rem=cum_sum%k;
            if( rem<0) rem += k;
            if(freq.find(rem)!=freq.end()){
                ans += freq[rem];
            }
            freq[rem]++;
        }
        return ans;
    }
};