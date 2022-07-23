class Solution {
public:
    
    void allSubsequences(vector<int>&singleSubs,vector<int>nums,int idx,int n,vector<vector<int>>&res){
        if(idx>=n) {
            res.push_back(singleSubs);
            return;
        }
        singleSubs.push_back(nums[idx]);
        allSubsequences(singleSubs,nums,idx+1,n,res);
        singleSubs.pop_back();
        allSubsequences(singleSubs,nums,idx+1,n,res);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>singleSubs;
        allSubsequences(singleSubs,nums,0,nums.size(),res);
        return res;
    }
};