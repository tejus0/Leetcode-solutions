// https://leetcode.com/problems/course-schedule

class Solution {

    int find(int x,vector<int>& par){
        if(par[x]==-1) return x;
        return find(par[x],par);
    }

    bool Union(int a, int b,vector<int>& par){
        int x = find(a,par);
        int y= find(b,par);
        if(x!=y) {
            par[x]=y;
            return true;
        }
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> par(numCourses,-1);
        for(auto i: prerequisites){
           if(!Union(i[0],i[1],par))
                return false;
        }
        return true;
    }
};