// https://leetcode.com/problems/lexicographically-smallest-equivalent-string

class Solution {
public:
    //int par[26];
    
    int find(int x,vector<int>& par){
        if(par[x]==-1) return x;
        return par[x]=find(par[x],par);
    }
    
    void Union(int x, int y,vector<int>& par) {
        x = find(x,par);
        y = find(y,par);
        
        if (x != y) 
        par[max(x, y)] = min(x, y); 
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        //memset(par, -1, sizeof(par));
        vector<int> par(26,-1);
        for (auto i = 0; i < s1.size(); ++i) 
            Union(s1[i] - 'a', s2[i] - 'a',par);
        
        for(auto i=0;i<baseStr.size();i++) 
            baseStr[i]=find(baseStr[i]-'a',par)+'a';

        return baseStr;
    }
};