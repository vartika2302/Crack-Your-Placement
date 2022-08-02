class Solution{
public:

    int f(int idx, int W, int val[], int wt[],vector<vector<int>>& dp) {
        
        // Base case
        if(idx==0) {
            if(wt[0]>W) return 0;
            else return val[0]*(W/wt[0]);
        }
        if(dp[idx][W]!=-1) return dp[idx][W];
        int not_pick = 0 + f(idx-1,W,val,wt,dp);
        int pick = INT_MIN;
        if(wt[idx]<=W) pick = val[idx] + f(idx,W-wt[idx],val,wt,dp);
        return dp[idx][W]=max(pick,not_pick);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
        vector<vector<int>> dp(N,vector<int>(W+1,-1));
        return f(N-1,W,val,wt,dp);
    }
};
