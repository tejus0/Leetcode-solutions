// https://leetcode.com/problems/course-schedule

class Solution {

    bool isCycleDAG(vector<int>* adj, int j, vector<bool>& visited){
        if(visited[j]==true) return true;
        for(auto k : adj[j]){
            if(isCycleDAG(adj,k,visited)){
                return true;
            }
        }
        visited[j]=false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n,false);
        vector<int> adj[n];
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        } 
        for(int i=0;i<n;i++){
            visited[i]=true;
            for(auto j: adj[i]){
                if(isCycleDAG(adj,j,visited)){
                    return false;
                }
            }
            visited[i]=false;
        }
        return true;
    }
};