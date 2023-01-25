// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ans;
        int ind=-1;
        int minimum=INT_MAX;
        int maximum=INT_MIN;
        for(int i=0;i<n;i++){
           // minimum=min(prices.at(i),minimum);
            if(prices.at(i)<minimum){
                minimum=prices.at(i);
                ind=i;
            }
            maximum=max(maximum,prices.at(i)-minimum);
        }
        ans=maximum;
        return ans;
    }
};