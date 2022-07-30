class Solution {
public:
    
    // MEMOIZATION
    bool f(int idx,int target,vector<int>& nums,vector<vector<int>>& dp) {
        if(target==0) return true;
        if(idx==0) return nums[0]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool take = false;
        if(target >= nums[idx]) take = f(idx-1,target-nums[idx],nums,dp);
        bool not_take = f(idx-1,target,nums,dp);
        return dp[idx][target]=take | not_take;
    }
    

    
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = 0;
        for(int i=0;i<n;i++){
            s += nums[i];
        }
        if(s&1) return false;
        // vector<vector<int>> dp(n,vector<int>((s/2)+1,-1));
        // return f(n-1,s/2,nums,dp);
        
        
        // TABULATION
        vector<vector<bool>> dp(n,vector<bool>((s/2)+1,0));
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        
        // Imp condition
        if (nums[0]<=s/2) dp[0][nums[0]]=true;
        
        for(int idx=1;idx<n;idx++){
            for(int target=1;target<=(s/2);target++){
                bool take=false;
                if(target>=nums[idx]) take = dp[idx-1][target-nums[idx]];
                bool not_take=dp[idx-1][target];
                dp[idx][target] = take | not_take;
            }
        }
        return dp[n-1][s/2];
    }
};