// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans;
        int ind=-1;
        int minimum=INT_MAX;
        for(int i=0;i<n;i++){
           // minimum=min(prices.at(i),minimum);
            if(prices.at(i)<minimum){
                minimum=prices.at(i);
                ind=i;
            }
        }
        int maximum=INT_MIN;
        for(int i=ind;i<prices.size();i++){
            maximum=max(maximum,prices.at(i));
        }
        ans=maximum-prices.at(ind);
        return ans;
    }
};