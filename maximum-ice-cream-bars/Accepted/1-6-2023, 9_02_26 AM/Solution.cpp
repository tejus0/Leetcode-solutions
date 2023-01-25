// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        int n= costs.size();
        sort(costs.begin(),costs.end());
        if(coins<costs[0]) return 0;
        for(auto& it: costs){
            if(coins>=it){
                ans++;
                coins -= it;
            }
            else break;
        }
        return ans;
    }
};