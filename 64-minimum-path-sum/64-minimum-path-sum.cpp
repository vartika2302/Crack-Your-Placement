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
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,grid);
        return fMem(m-1,n-1,grid,dp);
    }
};