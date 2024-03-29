class Solution {
private:
    int f(int idx, vector<int>& nums, map<int,int>& mpp, vector<int>& dp) {
        if(idx<0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int not_pick = f(idx-1,nums,mpp,dp);
        int pick=nums[idx]*mpp[nums[idx]]+f(idx-mpp[nums[idx]]-mpp[nums[idx]-1],nums,mpp,dp);
        return dp[idx]=max(not_pick,pick);
    }
    
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
            mpp[nums[i]]++;
        // vector<int>dp(n,-1);
        // return f(n-1,nums,mpp,dp);
        
        
        vector<int>dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++) {
            int not_pick = dp[i-1];
            int pick=nums[i]*mpp[nums[i]];
            int temp = mpp[nums[i]]+mpp[nums[i]-1];
            if(i>=temp) pick+=dp[i-temp];
            dp[i]=max(pick,not_pick);
        }
        return dp[n-1];
    }
};