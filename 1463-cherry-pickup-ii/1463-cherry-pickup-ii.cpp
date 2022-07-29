class Solution {
public:
    
    // RECURSION
    int f(int i,int j1,int j2,vector<vector<int>>& grid) {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++) {
            for(int dj2=-1;dj2<=1;dj2++) {
                if(j1==j2) maxi=max(maxi,grid[i][j1]+f(i+1,j1+dj1,j2+dj2,grid));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+f(i+1,j1+dj1,j2+dj2,grid));
            }
        }
        return maxi;
    }
    
    
    // MEMOIZATION
    int fMem(int i,int j1,int j2,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
        if(j1<0 || j1>=grid[0].size() || j2<0 || j2>=grid[0].size()) return -1e8;
        if(i==grid.size()-1){
            if(j1==j2) return grid[i][j1];
            else return grid[i][j1]+grid[i][j2];
        }
        if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];
        int maxi=INT_MIN;
        for(int dj1=-1;dj1<=1;dj1++) {
            for(int dj2=-1;dj2<=1;dj2++) {
                if(j1==j2) maxi=max(maxi,grid[i][j1]+fMem(i+1,j1+dj1,j2+dj2,grid,dp));
                else maxi=max(maxi,grid[i][j1]+grid[i][j2]+fMem(i+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        return dp[i][j1][j2]=maxi;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // int maxi=INT_MIN;
        // return f(0,0,n-1,grid);
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(m,vector<int>(n,-1)));
        return fMem(0,0,n-1,grid,dp);
    }
};