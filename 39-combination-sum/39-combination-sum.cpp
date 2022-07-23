class Solution {
public:
    
    void combinationHelper(vector<int>&candidates,vector<vector<int>>&res,vector<int>&comb,int idx,int target,int n) {
        if(idx==n) {
            if(target==0) {
                res.push_back(comb);
            }
            return;
        }
        if(candidates[idx]<=target) {
            // pick case
            comb.push_back(candidates[idx]);
            combinationHelper(candidates,res,comb,idx,target-candidates[idx],n);
            comb.pop_back();
        }
        // not pick case
        combinationHelper(candidates,res,comb,idx+1,target,n);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>comb;
        combinationHelper(candidates,res,comb,0,target,candidates.size());
        return res;
    }
};