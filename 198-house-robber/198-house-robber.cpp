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
        return fMem(n-1,nums,dp);
    }
};