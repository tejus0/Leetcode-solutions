// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> freq;
        int ans=0, round;
        for(auto& it : tasks){
            freq[it]++;
        }
        for(auto& it: freq ){
            int round=it.second;
            if(round==1)
                return -1;
            if(round%3==0)
                ans += round/3;
            else
                ans += round/3 +1; 
        }
        return ans;
    }
};