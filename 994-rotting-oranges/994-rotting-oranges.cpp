class Solution {
public:
    // Sc - O(n*m)
    // tc - O(n*m)+O(4*n*m)
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<pair<int,int>,int>>q;
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    vis[i][j]=2;
                    q.push({{i,j},0});
                }
                if(grid[i][j]==1) cntFresh++;
            }
        }
        
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,-1,0,+1};
        int cnt=0;
        int mtime = 0;
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            mtime=max(mtime,time);
            for(int i=0;i<4;i++){
                int newRow = row+dx[i];
                int newCol = col+dy[i];
                if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && grid[newRow][newCol]==1 && !vis[newRow][newCol]){
                    cnt++;
                    vis[newRow][newCol]=2;
                    q.push({{newRow,newCol},time+1});
                }
            }
        }
        
        if(cnt!=cntFresh) return -1;
        return mtime;
    }
};