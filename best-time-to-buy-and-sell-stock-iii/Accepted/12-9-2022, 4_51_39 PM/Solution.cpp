// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans;
        int ind=-1;
        int cost1=INT_MAX;
        int profit1=INT_MIN;
        int cost2=INT_MAX;
        int profit2=INT_MIN;
        for(int i=0;i<n;i++){
            cost1=min(cost1,prices[i]);
            profit1=max(profit1,prices[i]-cost1);
            cost2=min(cost2,prices[i]-profit1);
            profit2=max(profit2,prices[i]-cost2);
        }
        return profit2;
    }
};