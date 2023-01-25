// https://leetcode.com/problems/max-area-of-island

class Solution {
public:
    int n, m, cnt, vis[55][55];
    vector<vector<int>> grids;

    bool valid(int x, int y) {
        if(x >= 0 and x <n and y >= 0 and y < m and !vis[x][y] and grids[x][y]) return true;
        else return false;
    }

    void dfs(int x, int y) {
        if(valid(x, y)) {
            cnt++;
            vis[x][y] = 1;
            dfs(x+1, y);
            dfs(x-1, y);
            dfs(x, y+1);
            dfs(x, y-1);
        }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        memset(vis, 0, sizeof(vis));
        grids = grid;
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(valid(i, j)) {
                    cnt = 0;
                    dfs(i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        return ans;
    }
};