class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int m, int n, int& maxArea) {
        vis[i][j] = 1;
        int delx[] = {-1,0,+1,0};
        int dely[] = {0,+1,0,-1};
        
        queue<pair<int,int>>q;
        q.push({i,j});
        int area=1;
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int idx=0;idx<4;idx++) {
                int newx = x+delx[idx];
                int newy = y+dely[idx];
                if(newx>=0 && newy>=0 && newx<m && newy<n && !vis[newx][newy] && grid[newx][newy]==1) {
                    q.push({newx,newy});
                    vis[newx][newy]=1;
                    area++;
                }
            }
        }
        maxArea = max(maxArea,area);
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        int maxArea = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && grid[i][j]==1) {
                    bfs(i,j,grid,vis,m,n,maxArea);
                }
            }
        }
        
        return maxArea;
    }
};