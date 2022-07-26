class Solution {
public:
    
    // RECURSION
    // int climbStairs(int n) {
    //     if(n==0) return 1;
    //     if(n==1) return 1;
    //     int first = climbStairs(n-1);
    //     int second = climbStairs(n-2);
    //     return first+second;
    // }
    
    
    // MEMOIZATION - TOP-DOWN
//     int solve(int n,vector<int>& dp){
//         if(n<=1) return 1;
//         if(dp[n]!=-1) return dp[n];
//         return dp[n] = solve(n-1,dp)+solve(n-2,dp);
//     }
    
//     int climbStairs(int n){
//         vector<int>dp(n+1,-1);
//         return solve(n,dp);
//     }
    
    
    // TABULATION - BOTTOM-UP
    
//     int climbStairs(int n) {
//         vector<int>dp(n+1,-1);
//         dp[0]=1;
//         dp[1]=1;
//         for(int i=2;i<=n;i++){
//             dp[i] = dp[i-1]+dp[i-2];
//         }
//         return dp[n];
//     }
    
    int climbStairs(int n){
        int prev=1;
        int prev2=1;
        for(int i=2;i<=n;i++){
            int curri = prev+prev2;
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
    
};