class Solution {
public:
    // RECURSION
    int f(int n,vector<int> nums) {
        if(n==0) return nums[0];
        if(n<0) return 0;
        int pick=nums[n]+f(n-2,nums);
        int notpick=0+f(n-1,nums);
        return max(pick,notpick);
    }
    
    // MEMOIZATION
    int fMem(int n,vector<int>& nums,vector<int>& dp) {
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=nums[n]+fMem(n-2,nums,dp);
        int notpick=0+fMem(n-1,nums,dp);
        return dp[n]=max(pick,notpick);
    }
        
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
       
        vector<int>temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int m=temp1.size();
         vector<int>dp1(m,-1);
        vector<int>dp2(m,-1);
        // return max(f(m-1,temp1),f(m-1,temp2));
        return max(fMem(m-1,temp1,dp1),fMem(m-1,temp2,dp2));
    }
};