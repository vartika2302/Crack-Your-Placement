class Solution {
public:
    // RECURSION
    // int tribonacci(int n) {
    //     if(n==0) return 0;
    //     if(n==1 or n==2) return 1;
    //     int first = tribonacci(n-3);
    //     int mid = tribonacci(n-2);
    //     int last = tribonacci(n-1);
    //     return first+mid+last;
    // }
    
    // MEMOIZATION
//     int solve(int n,vector<int>& dp){
//         if(n==0) return 0;
//         if(n==1 or n==2) return 1;
//         if(dp[n]!=-1) return dp[n];
//         int first = solve(n-3,dp);
//         int mid = solve(n-2,dp);
//         int last = solve(n-1,dp);
//         return dp[n]=first+mid+last;
//     }
    
    
//     int tribonacci(int n) {
//         vector<int>dp(n+1,-1);
//         return solve(n,dp);
//     }
    
    // TABULATION
//     int solve(int n,vector<int>& dp){
//         dp[0]=0;
//         if(n>=1) dp[1]=1;
//         if(n>=2) dp[2]=1;
//         for(int i=3;i<=n;i++){
//             dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
//         }
//         return dp[n];
//     }
    
//     int tribonacci(int n) {
//         vector<int>dp(n+1,-1);
//         return solve(n,dp);
//     }
    
    // Space optimization
    int tribonacci(int n) {
        int prev = 1;
        int prev2 = 1;
        int prev3 = 0;
        for(int i=3;i<=n;i++){
            int curr = prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        if(n==0) return prev3;
        else if(n==1) return prev2;
        else return prev;
    }
    
};