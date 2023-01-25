// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int max_area(vector<vector<int>>& grid,int i, int j, int m, int n,int& cnt){
        if(i<0 or j<0 or i>=m or j>=n or !grid[i][j]){
            return 0;
        }
        grid[i][j]=0;
        if(max_area(grid,i+1,j,m,n,cnt)) cnt++;;  //down
        if(max_area(grid,i-1,j,m,n,cnt))cnt++; //up
        if(max_area(grid,i,j+1,m,n,cnt))cnt++;  //right
        if(max_area(grid,i,j-1,m,n,cnt))cnt++;  // left

        return 1;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                int cnt=1;
                if(grid[i][j]){
                    max_area(grid,i,j,m,n,cnt);
                    ans=max(ans,cnt);
                }
            }
        }
        return ans;
    }
};