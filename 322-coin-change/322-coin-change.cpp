class Solution {
public:
    
    int f(int idx, vector<int>& coins, int target, vector<vector<int>> &dp) {
        if(idx==0) {
            if(target%coins[0]==0) return target/coins[0];
            return 1e9;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int not_take = 0 + f(idx-1,coins,target,dp);
        int take = 1e9;
        if(target>=coins[idx]) take = 1 + f(idx,coins,target-coins[idx],dp);
        return dp[idx][target] = min(take,not_take);
    }
    
    int coinChange(vector<int>& coins, int amount) {
        
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int ans = f(n-1,coins,amount,dp);
        if(ans==1e9) return -1;
        else return ans;
    }
};