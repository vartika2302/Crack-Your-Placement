class Solution {
private:
    void bfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis) {
        vis[i][j]=1;
        queue<pair<int,int>>q;
        q.push({i,j});
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // left
            if(col-1>=0 && col-1<n && grid[row][col-1]=='1' && !vis[row][col-1]){
                vis[row][col-1]=1;
                q.push({row,col-1});
            }
            // right
            if(col+1>=0 && col+1<n && grid[row][col+1]=='1' && !vis[row][col+1]){
                vis[row][col+1]=1;
                q.push({row,col+1});
            }
            // top
            if(row-1>=0 && row-1<m && grid[row-1][col]=='1' && !vis[row-1][col]){
                vis[row-1][col]=1;
                q.push({row-1,col});
            }
            // bottom
            if(row+1>=0 && row+1<m && grid[row+1][col]=='1' && !vis[row+1][col]){
                vis[row+1][col]=1;
                q.push({row+1,col});
            }
        }
        
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]=='1' && !vis[i][j]){
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};