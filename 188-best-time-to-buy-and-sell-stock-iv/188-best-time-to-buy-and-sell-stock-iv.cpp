class Solution {
private:
    int f(int idx, int buy, int cap, vector<int>& prices,vector<vector<vector<int>>>& dp,int n){
        
        if(cap==0 || idx==n) return 0;
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        
        // buy
        if(buy) return dp[idx][buy][cap]=max(-prices[idx]+f(idx+1,0,cap,prices,dp,n),f(idx+1,1,cap,prices,dp,n));
        // sell
        return dp[idx][buy][cap]=max(prices[idx]+f(idx+1,1,cap-1,prices,dp,n),f(idx+1,0,cap,prices,dp,n));
    }

public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        // return f(0,1,k,prices,dp,n);
        
        
        // Tabulation
        // vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        // Space optimized
        vector<vector<int>>after(2,vector<int>(k+1,0)),curr(2,vector<int>(k+1,0));
        
        for(int idx=(n-1);idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=k;cap++){
                    if(buy) curr[buy][cap] = max(-prices[idx]+after[0][cap],after[1][cap]);
                    else curr[buy][cap] = max(prices[idx]+after[1][cap-1],after[0][cap]);
                }
            }
            after=curr;
        }
        return after[1][k];
    }
};