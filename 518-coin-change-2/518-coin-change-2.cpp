class Solution {
public:
    
    int f(int idx, vector<int>& coins, int target, vector<vector<int>>& dp) {
        
        // Base cases
        if(idx==0) {
            if(target%coins[0]==0) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int not_pick = f(idx-1,coins,target,dp);
        int pick = 0;
        if(target>=coins[idx]) pick = f(idx,coins,target-coins[idx],dp);
        return dp[idx][target]=pick+not_pick;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return f(n-1,coins,amount,dp);
    }
};