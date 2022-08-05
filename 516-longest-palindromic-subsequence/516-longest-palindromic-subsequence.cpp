class Solution {
public:
    
    int f(int i,int j,string& s1,string& s2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(s1[i]==s2[j]) return dp[i][j] = 1+f(i-1,j-1,s1,s2,dp);
        return dp[i][j] = max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
    }
    
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        string s1 = s;
        reverse(s.begin(),s.end());
        // return f(n-1,n-1,oris,s,dp);
        
        vector<vector<int>>dp(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s1[i]==s[j]) {
                    dp[i][j] = 1;
                    if(i>0 && j>0) dp[i][j] += dp[i-1][j-1];
                }else{
                    int f = i>0 ? dp[i-1][j] : 0;
                    int s = j>0 ? dp[i][j-1] : 0;
                    dp[i][j] = max(f,s);
                }
            }
        }
        return dp[n-1][n-1];
    }
};