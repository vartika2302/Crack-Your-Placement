class Solution {
public:
    
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]){
                    dp[i][j]=1;
                    if(i>0 && j>0) dp[i][j]+=dp[i-1][j-1];
                }else{
                    int f = i>0 ? dp[i-1][j] :0;
                    int l = j>0 ? dp[i][j-1] :0;
                    dp[i][j] = max(f,l);
                }
            }
        }
        return n-dp[n-1][n-1];
    }
};