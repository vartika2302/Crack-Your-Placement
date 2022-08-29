class Solution {
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis,int dx[], int dy[], int m, int n) {
        vis[row][col]=1;
        for(int i=0;i<4;i++) {
          int newRow = row+dx[i];
          int newCol = col+dy[i];
          if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && board[newRow][newCol]=='O' && !vis[newRow][newCol]){
            dfs(newRow, newCol, board, vis, dx, dy, m, n);  
          }
        }
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,-1,0,+1};
        
        // traverse rows
        
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,board,vis,dx,dy,m,n);
            }
            if(!vis[m-1][j] && board[m-1][j]=='O'){
                dfs(m-1,j,board,vis,dx,dy,m,n);
            }
        }
        
        // traverse columns
        
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis,dx,dy,m,n);
            }
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,vis,dx,dy,m,n);
            }
        }
        
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
        
    }
};