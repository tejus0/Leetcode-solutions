// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans=0;
        int n=time.size();
        int freq[60]={0};
        for(int i=0;i<n;i++){
            freq[time[i]%60]++;
        }
        if(freq[0]>0) ans=(freq[0]*(freq[0]-1))/2;
        for(int i= 1;i<30;i++){
            ans+=freq[i]*freq[60-i];
        }
        if(freq[30]) ans+=(freq[30]*(freq[30]-1))/2;
         return ans;
    }
};