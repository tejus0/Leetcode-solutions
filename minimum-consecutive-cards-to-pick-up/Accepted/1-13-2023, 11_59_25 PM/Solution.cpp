// https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up

class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        int n= cards.size();
        int ans=1e9;
        map<int,int> loc;
        for(int i=0 ;i<n;i++){
            if(loc.find(cards[i])!=loc.end()){
                if(i-loc[cards[i]]<ans){
                    ans=i-loc[cards[i]]+1;
                }
            }
            loc[cards[i]]=i;
        }
        for(auto i: loc) cout<<i.second<<endl;
        return ans==1e9 ? -1 : ans;
    }
};