// https://leetcode.com/problems/course-schedule

class Solution {

    bool isCyclicDAG(vector<int>* adj, vector<bool>& visited, int j){
        if(visited[j]==true) return true;
        if(adj[j].size()==0) return false;
        visited[j]=true;
        for(auto k : adj[j]){
            if(isCyclicDAG(adj,visited,k)){
                return false;
            }
        }
        visited[j]=false;
        adj[j]={};
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
            if(isCyclicDAG(adj,visited,i)) return false;
        }
        return true;
    }
};