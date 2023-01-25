// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60


class Solution {
public:
    long long int numPairsDivisibleBy60(vector<int>& time) {
        long long int ans = 0;
        vector<long long int> cnt(60,0);
        for (int i = 0; i < time.size(); i ++) cnt[time[i] % 60] += 1;
        for (int i = 1; i< 30; i++) ans += (cnt[i] * cnt[60 - i]);
        if(cnt[0]){
          ans+=(cnt[0]*(cnt[0] - 1))/2 ;
        }
        if(cnt[30]){
          ans+= ((cnt[30] - 1)*cnt[30] )/2;
        }
        // cout << n/2 << endl;
        return ans ;
    }
};