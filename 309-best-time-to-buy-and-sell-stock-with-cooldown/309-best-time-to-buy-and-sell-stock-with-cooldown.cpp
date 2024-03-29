class Solution {
private:
    // REC + MEM
    int f(int idx, int buy, vector<int>& prices,int n, vector<vector<int>>& dp) {
        if(idx>=n) return 0;
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        if(buy) return dp[idx][buy]=max(-prices[idx]+f(idx+1,0,prices,n,dp),f(idx+1,1,prices,n,dp));
        return dp[idx][buy]=max(prices[idx]+f(idx+2,1,prices,n,dp),f(idx+1,0,prices,n,dp));
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<int>>dp(n,vector<int>(2,-1));
        // return f(0,1,prices,n,dp);
        
        
        // Tabulation
        // vector<vector<int>>dp(n+2,vector<int>(2,0));
        // for(int idx=(n-1);idx>=0;idx--){
        //     for(int buy=0;buy<=1;buy++){
        //         if(buy) dp[idx][buy] = max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
        //         else dp[idx][buy] = max(prices[idx]+dp[idx+2][1],dp[idx+1][0]);
        //     }
        // }
        // return dp[0][1];
        
        // 2nd Tab
         vector<vector<int>>dp(n+2,vector<int>(2,0));
        for(int idx=(n-1);idx>=0;idx--){
            dp[idx][1] = max(-prices[idx]+dp[idx+1][0],dp[idx+1][1]);
            dp[idx][0] = max(prices[idx]+dp[idx+2][1],dp[idx+1][0]);   
        }
        return dp[0][1];
        
        
        
        // Space optimized
         vector<int>ahead2(2,0),ahead1(2,0),curr(2,0);
        for(int idx=(n-1);idx>=0;idx--){
            curr[1] = max(-prices[idx]+ahead1[0],ahead1[1]);
            curr[0] = max(prices[idx]+ahead2[1],ahead1[0]);  
            ahead2=ahead1;
            ahead1=curr;
        }
        return ahead1[1];
        
    }
};