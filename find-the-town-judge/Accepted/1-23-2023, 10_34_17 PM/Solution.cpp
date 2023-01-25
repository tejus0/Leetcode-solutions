// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        int ans=-1;
        if(n==1) return 1;
        vector<int> trustedBy(n+1,0);
        vector<int> truster(n+1,0);
        for(auto& i: trust){
            trustedBy[i[1]]++;
            truster[i[0]]++;
        }
        for(int i=0;i<=n;i++){
            if(trustedBy[i]==n-1 and truster[i]==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};