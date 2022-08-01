class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int f(int idx,int W,int wt[],int val[],vector<vector<int>>& dp) {
        
        // Base cases
        if(idx == 0) {
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[idx][W]!=-1) return dp[idx][W];
        int not_take = 0 + f(idx-1,W,wt,val,dp);
        int take = INT_MIN;
        if(wt[idx]<=W) take = val[idx] + f(idx-1,W-wt[idx],wt,val,dp);
        return dp[idx][W]=max(take,not_take);
    }
    
    
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
    //   vector<vector<int>> dp(n,vector<int>(W+1,-1));
    //   return f(n-1,W,wt,val,dp);
    
    // vector<vector<int>> dp(n,vector<int>(W+1,0));
       vector<int>prev(W+1,0);
       for(int w=wt[0];w<=W;w++){
           prev[w]=val[0];
       }
       
       for(int i=1;i<n;i++){
           for(int weight=W;weight>=0;weight--){
               int not_take = 0;
               if(i>0) not_take+=prev[weight];
               int take=INT_MIN;
               if(weight>=wt[i]) take = val[i]+prev[weight-wt[i]];
               prev[weight] = max(take,not_take);
           }
       }
       return prev[W];
    }
};
