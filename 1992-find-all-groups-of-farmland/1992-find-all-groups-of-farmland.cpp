class Solution {
private:
    void bfs(int x, int y, vector<vector<int>>& land, vector<vector<int>>& vis, vector<int>& t) {
        vis[x][y] = 1;
        int m = land.size();
        int n = land[0].size();
        queue<pair<int,int>>q;
        q.push({x,y});
        int dx[]={0,-1,0,+1};
        int dy[]={-1,0,+1,0};
        int currx,curry;
        while(!q.empty()) {
            currx = q.front().first;
            curry = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                
                    int nx = currx+dx[i];
                    int ny = curry+dy[i];
                    if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && land[nx][ny]==1) {
                        vis[nx][ny]=1;
                        q.push({nx,ny});
                    }
            
            }
        }
        t.push_back(currx);
        t.push_back(curry);
      
    }
    
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        vector<vector<int>>coordinates;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(!vis[i][j] && land[i][j]==1) {
                    vector<int>t;
                    t.push_back(i);
                    t.push_back(j);
                    bfs(i,j,land,vis,t);
                    coordinates.push_back(t);
                }
            }
        }
        
        return coordinates;
    }
};