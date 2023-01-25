// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree

class Solution {
public:
    vector<int> adj[100005];

    pair<int,int> dfs(int node, int parent,vector<bool>& hasApple){
        pair<int,int>v ={0,hasApple[node]};
        for(int i: adj[node]){
            if(i!=parent){
                pair<int,int> x= dfs(i,node,hasApple);
                v.first += (2+ x.first)*x.second;
                v.second |= x.second;
            }
        }
        return v;
    } 

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return dfs(0,0,hasApple).first;
    }
};