// https://leetcode.com/problems/course-schedule

class Solution {

    bool isCycleDAG(vector<int>* adj, int j, vector<int>& visited){
        if(visited[j]==2) return true;
        visited[j]=2;
        for(auto k : adj[j]){
            if(isCycleDAG(adj,k,visited)){
                return true;
            }
        }
        visited[j]=1;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> visited(n,0);
        vector<int> adj[n];
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        } 
        for(int i=0;i<n;i++){
            visited[i]=0;
            for(auto j: adj[i]){
                if(isCycleDAG(adj,j,visited)){
                    return false;
                }
            }
        }
        return true;
    }
};