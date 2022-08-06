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
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,p,dp);
        
        
        // TABULATION
        // vector<vector<int>>dp(n,vector<int>(m,0));
        
    }
};