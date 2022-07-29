class Solution {
public:
    
    // RECURSION
    int f(int n,vector<int>& nums) {
        if(n==0) return nums[0];
        if(n<0) return 0;
        int pick = nums[n]+f(n-2,nums);
        int notpick = 0+f(n-1,nums);
        return max(pick,notpick);
    }
    
    // MEMOIZATION
    int fMem(int n,vector<int>& nums,vector<int>& dp){
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick = nums[n]+fMem(n-2,nums,dp);
        int notpick = 0+fMem(n-1,nums,dp);
        return dp[n] = max(pick,notpick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        // return f(n-1,nums);
        // return fMem(n-1,nums,dp);
        
        // TABULATION
        // dp[0]=nums[0];
        // for(int i=1;i<n;i++){
        //     int pick = nums[i];
        //     if(i>1) pick+=dp[i-2];
        //     int notpick = 0+dp[i-1];
        //     dp[i]=max(pick,notpick);
        // }
        // return dp[n-1];
        
        // SPACE OPTIMIZATION;
        int prev2;
        int prev=nums[0];
        for(int i=1;i<n;i++){
            int pick = nums[i];
            if(i>1) pick+=prev2;
            int notpick=0+prev;
            int curr = max(pick,notpick);
            prev2=prev;
            prev=curr;
        }
        return prev;
        
    }
};