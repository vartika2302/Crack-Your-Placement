class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) 
            return -1;
        if(n==1) 
            return 1;
        vector<vector<int>>vis(n,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        vis[0][0]=1;
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=-1;i<=1;i++) {
                for(int j=-1;j<=1;j++) {
                    int nx = x+i;
                    int ny = y+j;
                    if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny] && grid[nx][ny]==0) {
                        if(nx==(n-1) && ny==(n-1))
                            return d+1;
                        q.push({{nx,ny},d+1});
                        vis[nx][ny]=1;
                    }
                }
            }
        }
        return -1;
    }
};