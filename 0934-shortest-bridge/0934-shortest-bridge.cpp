class Solution {
private:
    void bfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis) {
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j]=1;
        int n = grid.size();
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        while(!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny] && grid[nx][ny]==1) {
                    q.push({nx,ny});
                    vis[nx][ny]=1;
                }
            }
        }
    }
    
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        int fl=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]==1) {
                    fl=0;
                    bfs(i,j,grid,vis);
                    break;
                }
            }
            if(fl==0)
                break;
        }
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<n;j++) {
        //         cout<<vis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(vis[i][j]==1) {
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty()) {
            int x = q.front().first.first;
            int y = q.front().first.second;
            int count = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = x+dx[i];
                int ny = y+dy[i];
                if(nx>=0 && ny>=0 && nx<n && ny<n && !vis[nx][ny]) {
                    if(grid[nx][ny]==0) {
                        q.push({{nx,ny},count+1});
                        vis[nx][ny]=1;
                    }
                    else {
                        return count;
                    }
                }
            }
        }
        return 0;
    }
};