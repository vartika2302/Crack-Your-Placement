class Solution {
public:
    // RECURSION & MEMOIZATION
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
        // vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        // return f(n-1,coins,amount,dp);
        
        
        // TABULATION
//         vector<vector<int>> dp(n,vector<int>(amount+1,0));
        
        
//         for(int t=0;t<=amount;t++){
//             dp[0][t] = (t%coins[0]==0) ? 1 : 0;
//         }
        
//         for(int i=1;i<n;i++){
//             for(int t=0;t<=amount;t++){
//                 int not_take = dp[i-1][t];
//                 int take=0;
//                 if(t>=coins[i]) take = dp[i][t-coins[i]];
//                 dp[i][t] = not_take+take;
//             }
//         }
//         return dp[n-1][amount];
        
        
        // SPACE OPTIMIZATION
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int t=0;t<=amount;t++){
            prev[t] = (t%coins[0]==0) ? 1 : 0;
        }
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                 int not_take = prev[t];
                int take=0;
                if(t>=coins[i]) take = curr[t-coins[i]];
                curr[t] = not_take+take;
            }
            prev = curr;
        }
        return prev[amount];
        
        
        
    }
};