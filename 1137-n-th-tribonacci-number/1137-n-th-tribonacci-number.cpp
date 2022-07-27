class Solution {
public:
    // int tribonacci(int n) {
    //     if(n==0) return 0;
    //     if(n==1 or n==2) return 1;
    //     int first = tribonacci(n-3);
    //     int mid = tribonacci(n-2);
    //     int last = tribonacci(n-1);
    //     return first+mid+last;
    // }
    
    int solve(int n,vector<int>& dp){
        if(n==0) return 0;
        if(n==1 or n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        int first = solve(n-3,dp);
        int mid = solve(n-2,dp);
        int last = solve(n-1,dp);
        return dp[n]=first+mid+last;
    }
    
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};