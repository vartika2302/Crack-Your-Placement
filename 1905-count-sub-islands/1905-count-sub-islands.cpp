class Solution {
private:
    void dfs(int i, int j, vector<vector<int>>& grid2, vector<vector<int>>& vis, vector<pair<int,int>>& t, int m ,int n, int dx[], int dy[]) {
        vis[i][j]=1;
        t.push_back({i,j});
        for(int idx=0;idx<4;idx++) {
            int ni = i+dx[idx];
            int nj = j+dy[idx];
            if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj] && grid2[ni][nj]==1) {
                dfs(ni,nj,grid2,vis,t,m,n,dx,dy);
            }
        }
    }
    
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size();
        int n = grid2[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<pair<int,int>>>islands;
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && grid2[i][j]==1) {
                    vector<pair<int,int>>t;
                    dfs(i,j,grid2,vis,t,m,n,dx,dy);
                    islands.push_back(t);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<islands.size();i++) {
            int fg=1;
            for(int j=0;j<islands[i].size();j++) {
                if(grid1[islands[i][j].first][islands[i][j].second]==0) {
                    fg=0;
                    break;
                }
            }
            if(fg==1) {
                count++;
            }
        }
        return count;
    }
};