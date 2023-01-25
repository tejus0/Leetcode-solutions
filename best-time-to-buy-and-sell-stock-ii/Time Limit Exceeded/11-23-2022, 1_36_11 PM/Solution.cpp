// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution {
public:
    int dp(int ind,vector<int> prices, int buy , int n){
        
        if(ind==n){
            return 0;
        }
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+dp(ind+1,prices,0,n),0+dp(ind+1,prices,1,n));
        }
        else{
            profit=max(prices[ind]+dp(ind+1,prices,1,n),0+dp(ind+1,prices,0,n));
        }
        return profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        return dp(0,prices,1,n);
            }
};