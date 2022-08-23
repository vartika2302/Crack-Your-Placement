class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& vis,int& cnt,int dRow[],int dCol[],int n, int m) {
        cnt+=4;
        vis[row][col]=1;
        for(int i=0;i<4;i++) {
            int newRow = row+dRow[i];
            int newCol = col+dCol[i];
            if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && grid[newRow][newCol]==1 && vis[newRow][newCol]){
                cnt-=1;
            }
            else if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && grid[newRow][newCol]==1 && !vis[newRow][newCol]) {
                cnt-=1;
                dfs(newRow,newCol,grid,vis,cnt,dRow,dCol,n,m);
            }
        }
        
    }
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int f=1;
        int cnt=0;
        int dRow[]={-1,0,+1,0};
        int dCol[]={0,-1,0,+1};
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    dfs(i,j,grid,vis,cnt,dRow,dCol,n,m);
                    f=0;
                    break;
                }
            }
            if(f==0) break;
        }
        return cnt;
    }
};