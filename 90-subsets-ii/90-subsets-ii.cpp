class Solution {
public:
    
    void subsetsHelper(vector<int>& nums,int idx,int n,set<vector<int>>& res,vector<int>& ds){
        if(idx == n) {
            res.insert(ds);
            return;
        }
        ds.push_back(nums[idx]);
        subsetsHelper(nums,idx+1,n,res,ds);
        ds.pop_back();
        subsetsHelper(nums,idx+1,n,res,ds);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        subsetsHelper(nums,0,nums.size(),res,ds);
        vector<vector<int>>fres(res.begin(),res.end());
        return fres;
    }
};