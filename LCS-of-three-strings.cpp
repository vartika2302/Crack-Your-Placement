// RECURSION + MEMOIZATION
int f(int i,int j,int k,string& A,string& B,string& C,vector<vector<vector<int>>>& dp) {
    if(i<0 || j<0 || k<0) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    if(A[i]==B[j] && B[j]==C[k]) return dp[i][j][k]=1+f(i-1,j-1,k-1,A,B,C,dp);
    return dp[i][j][k]=max(f(i-1,j,k,A,B,C,dp),max(f(i,j-1,k,A,B,C,dp),max(f(i,j,k-1,A,B,C,dp),max(f(i-1,j-1,k,A,B,C,dp),max(f(i,j-1,k-1,A,B,C,dp),f(i-1,j,k-1,A,B,C,dp))))));
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
    return f(n1-1,n2-1,n3-1,A,B,C,dp);
    
    
    
    
    
    
    // TABULATION
    vector<vector<vector<int>>> dp(n1,vector<vector<int>>(n2,vector<int>(n3,0)));
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<n3;k++){
                if(A[i]==B[j] && B[j]==C[k]) {
                    dp[i][j][k] = 1;
                    if(i>0 && j>0 && k>0) dp[i][j][k]+=dp[i-1][j-1][k-1];
                }
                else{
                    int a=0,b=0,c=0,d=0,e=0,f=0;
                    if(i>0) a=dp[i-1][j][k];
                    if(j>0) b=dp[i][j-1][k];
                    if(k>0) c=dp[i][j][k-1];
                    if(i>0 && j>0) d=dp[i-1][j-1][k];
                    if(j>0 && k>0) e=dp[i][j-1][k-1];
                    if(i>0 && k>0) f=dp[i-1][j][k-1];
                    dp[i][j][k]=max(a,max(b,max(c,max(d,max(e,f)))));
                }
            }
        }
    }
    return dp[n1-1][n2-1][n3-1];
    
    
    
    
    
    
    
    // SPACE OPTIMIZATION
    vector<vector<int>> prev(n2,vector<int>(n3,0)),curr(n2,vector<int>(n3,0));
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            for(int k=0;k<n3;k++){
                if(A[i]==B[j] && B[j]==C[k]) {
                    curr[j][k] = 1;
                    if(i>0 && j>0 && k>0) curr[j][k]+=prev[j-1][k-1];
                }
                else{
                    int a=0,b=0,c=0,d=0,e=0,f=0;
                    if(i>0) a=prev[j][k];
                    if(j>0) b=curr[j-1][k];
                    if(k>0) c=curr[j][k-1];
                    if(i>0 && j>0) d=prev[j-1][k];
                    if(j>0 && k>0) e=curr[j-1][k-1];
                    if(i>0 && k>0) f=prev[j][k-1];
                    curr[j][k]=max(a,max(b,max(c,max(d,max(e,f)))));
                }
            }
        }
        prev=curr;
    }
    return prev[n2-1][n3-1];
    
}
