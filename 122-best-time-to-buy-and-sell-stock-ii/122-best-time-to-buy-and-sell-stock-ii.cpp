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
        
//         // Tabulation
        
//         vector<vector<int>>dp(n+1,vector<int>(2,0));
//         dp[n][0] = dp[n][1] = 0;
//         for(int idx=(n-1);idx>=0;idx--){
//             for(int buy=0;buy<=1;buy++){
//                 if(buy) dp[idx][buy] = max(-prices[idx]+dp[idx+1][0],0+dp[idx+1][1]);
//                 else dp[idx][buy] = max(prices[idx]+dp[idx+1][1],0+dp[idx+1][0]);
//             }
//         }
//         return dp[0][1];
        
        
        // // Space optimised
        // vector<int>ahead(2,0),curr(2,0);
        // ahead[0] = ahead[1] = 0;
        // for(int idx=(n-1);idx>=0;idx--){
        //     for(int buy=0;buy<=1;buy++){
        //         if(buy) curr[buy] = max(-prices[idx]+ahead[0],0+ahead[1]);
        //         else curr[buy] = max(prices[idx]+ahead[1],0+ahead[0]);
        //     }
        //     ahead = curr;
        // }
        // return ahead[1];
        
        
        // Using four variables
        int aheadBuy = 0;
        int aheadNotBuy = 0;
        for(int idx=(n-1);idx>=0;idx--){
            // Buy
            int currBuy = max(-prices[idx]+aheadNotBuy,0+aheadBuy);
            
            // Not buy
            int currNotBuy = max(prices[idx]+aheadBuy,0+aheadNotBuy);
            aheadBuy = currBuy;
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy;
        
    }
};