class Solution {
    
private:
    // REC + MEM + COORDINATE SHIFT - TLE
    int f(int idx, int prev_idx, vector<int>& nums, int n, vector<vector<int>>& dp){
        // Base case
        if(idx==n) return 0;
        if(dp[idx][prev_idx+1]!=-1) return dp[idx][prev_idx+1];
        // Not take
        int not_take = 0+f(idx+1,prev_idx,nums,n,dp);
        // Take
        int take=0;
        if(prev_idx==-1 || nums[idx]>nums[prev_idx]) take = 1+f(idx+1,idx,nums,n,dp);
        return dp[idx][prev_idx+1]=max(take,not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>>dp(n,vector<int>(n+1,-1));
        // return f(0,-1,nums,n,dp);
        
        
        
        // TABULATION
        // vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        // for(int idx=(n-1);idx>=0;idx--){
        //     for(int prev=(idx-1);prev>=-1;prev--){
        //         int len = 0+dp[idx+1][prev+1];
        //         if(prev==-1 || nums[idx]>nums[prev]) len = max(len,1+dp[idx+1][idx+1]);
        //         dp[idx][prev+1]=len;
        //     }
        // }
        // return dp[0][-1+1];
        
        
        
        
        
        // SPACE OPTIMIZATION
        // vector<int>ahead(n+1,0),curr(n+1,0);
        // for(int idx=(n-1);idx>=0;idx--){
        //     for(int prev=(idx-1);prev>=-1;prev--){
        //         int len = 0+ahead[prev+1];
        //         if(prev==-1 || nums[idx]>nums[prev]) len = max(len,1+ahead[idx+1]);
        //         curr[prev+1]=len;
        //     }
        //     ahead=curr;
        // }
        // return curr[-1+1];
        
        
        
        
        // Tabulation - 2nd method
        // vector<int>dp(n,1),hash(n);
        // int maxi=1;
        // int lastIndex=0;
        // for(int idx=0;idx<n;idx++){
        //     hash[idx]=idx;
        //     for(int prev=0;prev<idx;prev++){
        //         if(nums[prev]<nums[idx] && 1+dp[prev]>dp[idx]){
        //              dp[idx]=1+dp[prev];
        //              hash[idx]=prev;
        //         }
        //     }
        //     if(dp[idx]>maxi){
        //         maxi=dp[idx];
        //         lastIndex=idx;
        //     }
        // }
        // vector<int>temp;
        // temp.push_back(nums[lastIndex]);
        // while(hash[lastIndex]!=lastIndex){
        //     lastIndex=hash[lastIndex];
        //     temp.push_back(nums[lastIndex]);
        // }
        // reverse(temp.begin(),temp.end());
        // for(auto it: temp) cout<<(it)<<" ";
        // cout<<endl;
        // return maxi;
        
        
        
        
        // LIS using Binary Search
        vector<int>temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                temp.push_back(nums[i]);
                len++;
            }else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
        
    }
    
};