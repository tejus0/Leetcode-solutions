// https://leetcode.com/problems/course-schedule

class Solution {

    bool isCyclicDAG(vector<int>* adj, vector<bool>& visited,vector<bool>& dfsVis, int j){
        visited[j]=true;
        dfsVis[j]=true;
        for(auto k : adj[j]){
            if(!visited[k] and isCyclicDAG(adj,visited,dfsVis,k)){
                return true;
            }
            else if(dfsVis[k]) return true;
        }
        dfsVis[j]=false;
        return false;
    }
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<bool> visited(n,false),dfsVis(n,false);
        vector<int> adj[n];
        for(auto i:prerequisites){
            adj[i[0]].push_back(i[1]);
        } 
        for(int i=0;i<n;i++){
            if(isCyclicDAG(adj,visited,dfsVis,i)) return false;
        }
        return true;
    }
};