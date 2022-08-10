class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>hash(n,0);
        int maxi=1;
        int lastIndex=0;
        for(int idx=1;idx<n;idx++){
            hash[idx]=idx;
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(nums[idx]%nums[prev_idx]==0 && dp[idx]<1+dp[prev_idx]){
                    dp[idx]=1+dp[prev_idx];
                    hash[idx]=prev_idx;
                }
            }
            if(dp[idx]>maxi){
                maxi=dp[idx];
                lastIndex=idx;
            }
        }
        
        vector<int>temp;
        temp.push_back(nums[lastIndex]);
        while(hash[lastIndex]!=lastIndex){
            lastIndex=hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }
        return temp;
    }
};