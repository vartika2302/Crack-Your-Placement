class Solution {

    private:
    
    // RECURSIVE + MEMOIZATION
    int f(int i,int j,string& s,string& t,vector<vector<int>>& dp){
        if(j==0) return 1;
        if(i==0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==t[j-1]) {
            return dp[i][j] = f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp);
        }
        return dp[i][j]=f(i-1,j,s,t,dp);
    }
   public: 
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,s,t,dp);
        
        // TABULATION
        // vector<vector<double>>dp(n+1,vector<double>(m+1,0));
        vector<double>prev(m+1,0),curr(m+1,0);
       //Base cases
        
        prev[0]=curr[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) curr[j] = prev[j-1]+prev[j];
                else curr[j] = prev[j];
            }
            prev=curr;
        }
            
        return (int)prev[m];
    }
};