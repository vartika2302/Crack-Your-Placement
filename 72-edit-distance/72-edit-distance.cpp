class Solution {
    
private:
    int f(int i, int j, string& word1, string& word2,vector<vector<int>>& dp) {
        // Base cases
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(word1[i]==word2[j]) return dp[i][j]=0 + f(i-1,j-1,word1,word2,dp);
        int insert = 1 + f(i,j-1,word1,word2,dp);
        int del = 1 + f(i-1,j,word1,word2,dp);
        int replace = 1 + f(i-1,j-1,word1,word2,dp);
        return dp[i][j]=min(insert,min(del,replace));
    }
        
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,word1,word2,dp);
        
        
        // TABULATION
        
//         vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        
//         for(int j=0;j<=m;j++) dp[0][j]=j;
//         for(int i=0;i<=n;i++) dp[i][0]=i;
        
//         for(int i=1;i<=n;i++){
//             for(int j=1;j<=m;j++){
//                 if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
//                 else dp[i][j] =1+ min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
//             }
//         }
//         return dp[n][m];
        
        
        // SPACE OPTIMIZATION
        
        vector<int>prev(m+1,0),curr(m+1,0);
        for(int j=0;j<=m;j++) prev[j] = j;
        
        for(int i=1;i<=n;i++){
            curr[0]=i; // 2nd base case
            for(int j=1;j<=m;j++){
                if(word1[i-1]==word2[j-1]) curr[j] = prev[j-1];
                else curr[j] = 1+min(curr[j-1],min(prev[j],prev[j-1]));
            }
            prev = curr;
        }
        
        return prev[m];
        
        
    }
};