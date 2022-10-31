class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        int cnt=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if((i==0 || i==(m-1) || j==0 || j==(n-1)) && grid[i][j]==1) {
                    q.push({i,j});
                    visited[i][j]=1;
                    cnt++;
                }
            }
        }
        
        int delx[] = {-1,0,+1,0};
        int dely[] = {0,+1,0,-1};
        
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int newx = x+delx[i];
                int newy = y+dely[i];
                
                if(newx>=0 && newy>=0 && newx<m && newy<n && !visited[newx][newy] && grid[newx][newy]==1) {
                    q.push({newx,newy});
                    visited[newx][newy]=1;
                    cnt++;
                }
            }
        }
        
        int total=0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1)
                    total++;
            }
        }
        
        return total-cnt;
        
    }
};