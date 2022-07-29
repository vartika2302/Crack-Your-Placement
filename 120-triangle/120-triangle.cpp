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
        return fMem(0,0,m,triangle,dp);
    }
};