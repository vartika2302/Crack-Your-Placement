class Solution {
public:
    // RECURSION
    int f(int row,int col,int n,vector<vector<int>>& matrix) {
        if(col<0 || col>=n) return 1e9;
        if(row==0) return matrix[0][col];
        int up=matrix[row][col]+f(row-1,col,n,matrix);
        int ld=matrix[row][col]+f(row-1,col-1,n,matrix);
        int rd=matrix[row][col]+f(row-1,col+1,n,matrix);
        return min(up,min(ld,rd));
    }
    
    // MEMOIZATION
    int fMem(int row,int col,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if(col<0 || col>=n) return 1e9;
        if(row==0) return matrix[0][col];
        if(dp[row][col]!=-1) return dp[row][col];
        int up=matrix[row][col]+fMem(row-1,col,n,matrix,dp);
        int ld=matrix[row][col]+fMem(row-1,col-1,n,matrix,dp);
        int rd=matrix[row][col]+fMem(row-1,col+1,n,matrix,dp);
        return dp[row][col]=min(up,min(ld,rd));
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int mini=INT_MAX;
        // for(int j=0;j<n;j++){
        //     mini=min(mini,f(n-1,j,n,matrix));
        // }
        
        // Memo
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        
        // for(int j=0;j<n;j++){
        //     mini=min(mini,fMem(n-1,j,n,matrix,dp));
        // }
        // return mini;
        
        
        
        // Tabulation
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                int up=matrix[i][j]+dp[i-1][j];
                int ld=matrix[i][j];
                if(j-1>=0) ld+=dp[i-1][j-1];
                else ld+=1e9;
                int rd=matrix[i][j];
                if(j+1<n) rd+=dp[i-1][j+1];
                else rd+=1e9;
                dp[i][j]=min(up,min(ld,rd));
            }
        }
       
        for(int j=0;j<n;j++){
            mini=min(mini,dp[n-1][j]);
        }
        return mini;
        
    }
};