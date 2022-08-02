class Solution {
public:
    
    // RECURSION AND MEMOIZATION
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
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // int ans = f(n-1,coins,amount,dp);
        // if(ans==1e9) return -1;
        // else return ans;
        
        // TABULATION
//         vector<vector<int>> dp(n,vector<int>(amount+1,0));
//         for(int i=0;i<=amount;i++){
//             dp[0][i] = (i%coins[0]==0 ? i/coins[0] : 1e9);
//         }
        
//         for(int i=1;i<n;i++){
//             for(int tar=0;tar<=amount;tar++){
//                 int not_take = 0 + dp[i-1][tar];
//                 int take = 1e9;
//                 if(tar>=coins[i]) take = 1 + dp[i][tar-coins[i]];
//                 dp[i][tar] = min(take,not_take);
//             }
//         }
//         return dp[n-1][amount]==1e9 ? -1 : dp[n-1][amount];
        
        // SPACE OPTIMIZATION
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int i=0;i<=amount;i++){
            prev[i] = (i%coins[0]==0 ? i/coins[0] : 1e9);
        }
        
        for(int i=1;i<n;i++){
            for(int tar=0;tar<=amount;tar++){
                int not_take = 0 + prev[tar];
                int take = 1e9;
                if(tar>=coins[i]) take = 1 + curr[tar-coins[i]];
                curr[tar] = min(take,not_take);
            }
            prev=curr;
        }
        return prev[amount]==1e9 ? -1 : prev[amount];
        
    }
};