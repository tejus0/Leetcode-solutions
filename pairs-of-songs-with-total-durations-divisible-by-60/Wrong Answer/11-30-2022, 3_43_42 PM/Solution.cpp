// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60


class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0, cnt[60] = {0};
        for (int i = 0; i < time.size(); i ++) cnt[time[i] % 60] += 1;
        for (int i = 1; i< 30; i ++) ans += (cnt[i] * cnt[60 - i]);
        int zeroes, thirty;
        if(cnt[0]){
         zeroes=(cnt[0] * (cnt[0] - 1) / 2 );
        }
        if(cnt[30]){
         thirty = (cnt[30] * (cnt[30] - 1) / 2);
        }
        return ans + zeroes + thirty;
    }
};