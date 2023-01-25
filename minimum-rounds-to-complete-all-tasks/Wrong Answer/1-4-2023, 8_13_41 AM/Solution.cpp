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
            if(round>=3){
                ans += round / 3;
                round %= 3;
            }
            if(round%2==0 and round>0){
                ans += round / 2;
                round %= 2;
            }
            else if(round){
                //cout<<ans;
                return -1;
            }
        }
        return ans;
    }
};