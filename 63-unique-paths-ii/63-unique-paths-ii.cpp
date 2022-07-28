class Solution {
public:
    
    // RECURSION
    int f(int i,int j,vector<vector<int>>& obstacleGrid) {
        if(i==0 && j==0) return (obstacleGrid[0][0]==1 ? 0 : 1);
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        int up = f(i-1,j,obstacleGrid);
        int left = f(i,j-1,obstacleGrid);
        return up+left;
    }
    
    
    // MEMOIZATION
    int fMem(int i,int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>& dp) {
        if(i==0 && j==0) return (obstacleGrid[0][0]==1 ? 0 : 1);
        if(i<0 || j<0 || obstacleGrid[i][j]==1) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = fMem(i-1,j,obstacleGrid,dp);
        int left = fMem(i,j-1,obstacleGrid,dp);
        return dp[i][j]=up+left;
    }
    
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return f(m-1,n-1,obstacleGrid);
        // return fMem(m-1,n-1,obstacleGrid,dp);
        
        // TABULATION
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    if(obstacleGrid[0][0]==1) dp[0][0]=0;
                    else dp[0][0]=1;
                }
                else if(obstacleGrid[i][j]==1) dp[i][j]=0;
                
                else{
                    int up=0,left=0;
                    if(i>0) up=dp[i-1][j];
                    if(j>0) left=dp[i][j-1];
                    dp[i][j]=up+left;
                }
            }
        }
        return dp[m-1][n-1];
        
    }
};