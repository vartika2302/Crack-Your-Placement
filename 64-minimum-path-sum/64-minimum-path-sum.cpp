class Solution {
public:
    // RECURSION
    int f(int i,int j,vector<vector<int>>& grid) {
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e+7;
        int up = grid[i][j]+f(i-1,j,grid);
        int left = grid[i][j]+f(i,j-1,grid);
        return min(left,up);
    }
    
    // MEMOIZATION
    int fMem(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e+7;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = grid[i][j]+fMem(i-1,j,grid,dp);
        int left = grid[i][j]+fMem(i,j-1,grid,dp);
        return dp[i][j]=min(left,up);
    }
    
    // TABULATION
    int fTab(int m,int n,vector<vector<int>>& grid,vector<vector<int>>& dp) {
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else{
                    int up=0,left=0;
                    up=grid[i][j]+(i>0 ? dp[i-1][j] :1e9+7);
                    left=grid[i][j]+(j>0 ? dp[i][j-1] :1e9+7);
                    dp[i][j]=min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid);
        // return fMem(m-1,n-1,grid,dp);
        return fTab(m,n,grid,dp);
    }
};