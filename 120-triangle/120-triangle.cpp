class Solution {
public:
    // RECURSION
    int f(int i,int j,int m,vector<vector<int>>& triangle) {
        if(i==m-1) return triangle[triangle.size()-1][j];
        int down = triangle[i][j]+f(i+1,j,m,triangle);
        int diagonal = triangle[i][j]+f(i+1,j+1,m,triangle);
        return min(down,diagonal);
    }
    
    // MEMOIZATION
    int fMem(int i,int j,int m,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        if(i==m-1) return triangle[m-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down = triangle[i][j]+fMem(i+1,j,m,triangle,dp);
        int diagonal = triangle[i][j]+fMem(i+1,j+1,m,triangle,dp);
        return dp[i][j]=min(down,diagonal);
    }
    
    
     
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int m = triangle.size();
        int n = triangle[m-1].size();
        // return f(0,0,m,triangle);
        vector<vector<int>>dp(m,vector<int>(n,-1));
        // return fMem(0,0,m,triangle,dp);
        
        
        
        //// TABULATION
        // BASE CASE
        
        // for(int j=0;j<n;j++){
        //     dp[m-1][j]=triangle[m-1][j];
        // }
        // for(int i=(m-2);i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int down = triangle[i][j]+dp[i+1][j];
        //         int diagonal = triangle[i][j]+dp[i+1][j+1];
        //         dp[i][j]=min(down,diagonal);
        //     }
        // }
        // return dp[0][0];
        
        
        
        // SPACE OPTIMIZATION
        vector<int>front(n,-1);
        for(int j=0;j<n;j++){
            front[j]=triangle[n-1][j];
        }
        
        for(int i=(n-2);i>=0;i--){
            vector<int>curr(n,0);
            for(int j=i;j>=0;j--){
                int down=triangle[i][j]+front[j];
                int diagonal = triangle[i][j]+front[j+1];
                curr[j] = min(down,diagonal);
            }
            front=curr;
        }
        return front[0];
        
    }
};