// https://leetcode.com/problems/longest-path-with-different-adjacent-characters

class Solution {
public:
    int solve(vector<int>adj[],string &s,int n,int par,int &ans)
    {
        int c=0;
        vector<int>v;
        for(auto i:adj[n])
        {
            if(i==par)
                continue;
            int x=solve(adj,s,i,n,ans);
            v.push_back(x);
        }
        sort(v.begin(),v.end(),greater<int>());
        int a=0,b=0,y=v.size();
        if(y>0)
            a=v[0];
        if(y>1)
            b=v[1];
        ans=max(ans,1+a+b);
        if(par!=-1 && s[n]!=s[par])
            return 1+max(a,b);
        return 0;
    }
    int longestPath(vector<int>&v, string s) {
        int n=v.size();
        vector<int>adj[n];
        for(int i=1;i<n;i++)
        {
            adj[i].push_back(v[i]);
            adj[v[i]].push_back(i);
        }
        int ans=1;
        int x=solve(adj,s,0,-1,ans);
        return ans;
    }
};