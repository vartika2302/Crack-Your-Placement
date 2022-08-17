class Solution {
    
private:
    int f(int idx, int n, vector<int>& nums, vector<int>& dp) {
        if(idx==n-1) return true;
        if(idx==n) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++) {
            if(f(idx+i,n,nums,dp)) return dp[idx]=true;
        }
        return dp[idx]=false;
    }
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        // vector<int>dp(n+1,-1);
        // return f(0,n,nums,dp);
        
        
        // Tabulation
        vector<int>dp(n+1,0);
        dp[n-1]=dp[n]=1;
        for(int i=n-2;i>=0;i--) {
            bool temp=false;
            for(int j=1;j<=nums[i];j++) {
                if(i+j<=n) temp=temp||dp[i+j];
                if(temp) break;
            }
            dp[i]=temp;
        }
        return dp[0];
        
    }
};