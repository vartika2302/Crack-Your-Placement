class Solution {
public:
    
    int f1(int idx, int buy, int noTranPoss, vector<int>& prices, vector<vector<vector<int>>>& dp1) {
        
        //base cases
        if(idx==prices.size()) return 0;
        if(noTranPoss==0) return 0;
        if(dp1[idx][buy][noTranPoss]!=-1) return dp1[idx][buy][noTranPoss];
        int profit=0;
        if(buy) {
            profit = max(-prices[idx]+f1(idx+1,0,noTranPoss,prices,dp1),0+f1(idx+1,1,noTranPoss,prices,dp1));
        }else {
            
            profit = max(prices[idx]+f1(idx+1,1,noTranPoss-1,prices,dp1),0+f1(idx+1,0,noTranPoss,prices,dp1));
        }
        return dp1[idx][buy][noTranPoss]=profit;
    }
    
    int f2(int idx, int buy, int noTranPoss, vector<int>& prices, vector<vector<vector<int>>>& dp2) {
        
        //base cases
        if(idx==prices.size()) return 0;
        if(noTranPoss==0) return 0;
        if(dp2[idx][buy][noTranPoss]!=-1) return dp2[idx][buy][noTranPoss];
        int profit=0;
        if(buy) {
            profit = max(-prices[idx]+f2(idx+1,0,noTranPoss,prices,dp2),0+f2(idx+1,1,noTranPoss,prices,dp2));
        }else {
            
            profit = max(prices[idx]+f2(idx+1,1,noTranPoss-1,prices,dp2),0+f2(idx+1,0,noTranPoss,prices,dp2));
        }
        return dp2[idx][buy][noTranPoss]=profit;
    }
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit1=0,profit2=0;
        int num1=1,num2=2;
        vector<vector<vector<int>>> dp1(n,vector<vector<int>>(2,vector<int>(3,-1)));
        vector<vector<vector<int>>> dp2(n,vector<vector<int>>(2,vector<int>(3,-1)));
        profit1 = f1(0,1,num1,prices,dp1);
        profit2 = f2(0,1,num2,prices,dp2);
        return max(profit1,profit2);
    }
};