class Solution {
private:
    
    // REC + MEM
    int f(int idx, int buy, vector<int>& prices,int& profit, vector<vector<int>>& dp) {
        if(idx==prices.size()) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy){
            profit = max(-prices[idx]+f(idx+1,0,prices,profit,dp),0+f(idx+1,1,prices,profit,dp));
        }else{
            profit = max(prices[idx]+f(idx+1,1,prices,profit,dp),0+f(idx+1,0,prices,profit,dp));
        }
        return dp[idx][buy]=profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        int profit;
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,prices,profit,dp);
        
        // Tabulation
        
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n][0] = dp[n][1] = 0;
        for(int idx=(n-1);idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                if(buy) dp[idx][buy] = max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);
                else dp[idx][buy] = max(prices[idx]+dp[idx+1][1],0+dp[idx+1][0]);
            }
        }
        return dp[0][1];
    }
};