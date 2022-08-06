class Solution {
    
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // Base cases
        if(i==0 && j==0) return true;
        if(i==0 && j>0){
            for(int k = 1;k<=j;k++){
                if(p[k-1]!='*') return false;
            }
            return true;
        }
        if(i>0 && j==0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i-1]==p[j-1] || p[j-1]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j-1]=='*') return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        return false;
    }
    
public:
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        // return f(n,m,s,p,dp);
        
        
        // TABULATION
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int j=1;j<=m;j++){
            bool flag = true;
            for(int k=1;k<=j;k++){
                if(p[k-1]!='*') {
                    flag = false;
                    break;
                }
            }
            dp[0][j] = flag;
        }
        for(int i=1;i<=n;i++){
            dp[i][0] = false;
        }
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?') dp[i][j] = dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j] = dp[i-1][j]||dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
        
    }
};