class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,1),cnt(n,1);
        int maxi=1;
        for(int idx=0;idx<n;idx++){
            for(int prev=0;prev<idx;prev++){
                if(nums[idx]>nums[prev] && 1+dp[prev]>dp[idx]) {
                    dp[idx]=1+dp[prev];
                    cnt[idx]=cnt[prev];
                }else if(nums[idx]>nums[prev] && 1+dp[prev]==dp[idx]){
                    cnt[idx]+=cnt[prev];
                }
            }
            maxi=max(maxi,dp[idx]);
        }
        
        int res=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) res+=cnt[i];
        }
        return res;
    }
};