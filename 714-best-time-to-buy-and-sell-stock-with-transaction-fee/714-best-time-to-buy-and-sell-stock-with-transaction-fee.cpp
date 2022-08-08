class Solution {
private:
    int f(int idx, int buy, vector<int>& prices, int n, int fee, vector<vector<int>>& dp) {
        if(idx==n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy) return dp[idx][buy]=max(-prices[idx]+f(idx+1,0,prices,n,fee,dp),f(idx+1,1,prices,n,fee,dp));
        return dp[idx][buy]=max(prices[idx]-fee+f(idx+1,1,prices,n,fee,dp),f(idx+1,0,prices,n,fee,dp));
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,n,fee,dp);
    }
};