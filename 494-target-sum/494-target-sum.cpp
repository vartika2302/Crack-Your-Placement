class Solution {
public:
    
    int f(int idx,vector<int>& nums,int tar,vector<vector<int>>& dp) {
        
        if(idx==0) {
            if(tar==0 && nums[idx]==0) return 2;
            if(tar==0 || tar==nums[idx]) return 1;
            else return 0;
        }
        if(dp[idx][tar]!=-1) return dp[idx][tar];
        int not_pick = f(idx-1,nums,tar,dp);
        int pick = 0;
        if(tar>=nums[idx]) pick = f(idx-1,nums,tar-nums[idx],dp);
        return dp[idx][tar]=pick+not_pick;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int totsum=0;
        int n = nums.size();
        int cnt0=0;
        for(int i=0;i<n;i++) {
            totsum+=nums[i];
            if(nums[i]==0) cnt0++;
        }
        
        int tar = (totsum-target);
        // if(tar==0) return pow(2,cnt0);
        if(tar<0 || tar%2) return 0;
        vector<vector<int>>dp(n,vector<int>(tar+1,-1));
        return f(n-1,nums,tar/2,dp);
        
    }
};