class Solution{
  public:
  
    int f(int idx,int price[],int target,vector<vector<int>>& dp) {
        
        // Base case
        if(idx==0) {
            return (target)*price[0];
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int not_take = 0 + f(idx-1,price,target,dp);
        int take = INT_MIN;
        if(target>=idx+1) take = price[idx] + f(idx,price,target-idx-1,dp);
        return dp[idx][target]=max(take,not_take);
    }
  
    int cutRod(int price[], int n) {
        //code here
       
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        return f(n-1,price,n,dp);
    }
};
