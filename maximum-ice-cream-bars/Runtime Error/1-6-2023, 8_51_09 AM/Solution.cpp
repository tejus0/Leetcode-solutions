// https://leetcode.com/problems/maximum-ice-cream-bars

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        int n= costs.size();
        int sum=accumulate(costs.begin(),costs.end(), 0);
        if(sum<=coins) return n;
        sort(costs.begin(),costs.end());
        for(auto& it: costs){
            if(coins>=it){
                cout<<"here"<<' ';
                ans++;
                coins -= it;
            }
            else break;
        }
        return ans;
    }
};