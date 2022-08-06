class Solution {
    
private:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        // Base cases
        if(i<0 && j<0) return true;
        if(i<0 && j>=0){
            for(int k = 0;k<=j;k++){
                if(p[k]!='*') return false;
            }
            return true;
        }
        if(i>=0 && j<0) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==p[j] || p[j]=='?') return dp[i][j]=f(i-1,j-1,s,p,dp);
        if(p[j]=='*') return dp[i][j]=f(i-1,j,s,p,dp) || f(i,j-1,s,p,dp);
        return false;
    }
    
public:
    
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,p,dp);
    }
};