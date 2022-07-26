#include<bits/stdc++.h>

int solve(int n,vector<int>& heights,vector<int>& dp){
    if(n==0) return 0;
    if(dp[n]!=-1) return dp[n];
   int left = solve(n-1,heights,dp)+abs(heights[n]-heights[n-1]);
   int right = INT_MAX;
    if(n>1)
       right = solve(n-2,heights,dp)+abs(heights[n]-heights[n-2]);
    return dp[n]=min(left,right);
}


int solveTab(int n,vector<int>& heights,vector<int>& dp){
    
    int prev=0;
    int prev2=0;
    for(int i=1;i<=n;i++){
        int left = prev+abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i>1) {
            right = prev2+abs(heights[i]-heights[i-2]);
        }
        int ans = min(left,right);
        prev2=prev;
        prev=ans;
    }
    return prev;
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int>dp(n+1,-1);
    int ans = solveTab(n-1,heights,dp);
    return ans;
}
