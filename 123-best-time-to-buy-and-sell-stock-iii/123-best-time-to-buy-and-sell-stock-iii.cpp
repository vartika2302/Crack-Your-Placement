class Solution {
    
private: 
    int f(int idx, int buy, int cap, vector<int>& prices, vector<vector<vector<int>>>& dp) {
        
        // Base cases
        if(cap==0) return 0;
        if(idx==prices.size()) return 0;
        
        
        if(dp[idx][buy][cap]!=-1) return dp[idx][buy][cap];
        int profit;
        
        if(buy) {
            profit = max(-prices[idx]+f(idx+1,0,cap,prices,dp),f(idx+1,1,cap,prices,dp));
        }
        else {
            profit = max(prices[idx]+f(idx+1,1,cap-1,prices,dp),f(idx+1,0,cap,prices,dp));
        }
        return dp[idx][buy][cap]=profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        // return f(0,1,2,prices,dp);
        
        
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        // Note: Base cases will not make any difference as initial value of dp is already 0.
        // BASE CASE 1
        for(int i=0;i<n;i++){
            for(int buy=0;buy<=1;buy++){
                dp[i][buy][0]=0;
            }
        }
        
        // BASE CASE 2
        for(int buy=0;buy<=1;buy++){
            for(int cap=0;cap<=2;cap++) {
                dp[n][buy][cap]=0;
            }
        }
        
        for(int idx=(n-1);idx>=0;idx--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    if(buy) dp[idx][buy][cap] = max(-prices[idx]+dp[idx+1][0][cap],dp[idx+1][1][cap]);
                    else dp[idx][buy][cap] = max(prices[idx]+dp[idx+1][1][cap-1],dp[idx+1][0][cap]);
                }
            }
        }
        return dp[0][1][2];
    }
};