class Solution {
public:
//    void subsetsHelper(vector<int>& nums,int idx,int n,set<vector<int>>& res,vector<int>& ds){
//         if(idx == n) {
//             res.insert(ds);
//             return;
//         }
//         ds.push_back(nums[idx]);
//         subsetsHelper(nums,idx+1,n,res,ds);
//         ds.pop_back();
//         subsetsHelper(nums,idx+1,n,res,ds);
//     }
    
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>>res;
//         vector<int>ds;
//         sort(nums.begin(),nums.end());
//         subsetsHelper(nums,0,nums.size(),res,ds);
//         vector<vector<int>>fres(res.begin(),res.end());
//         return fres;
//     }
        
    void subsetsHelper(vector<int>& nums,int idx,int n,vector<int>& ds,vector<vector<int>>& res) {
       res.push_back(ds);
        for(int i=idx;i<n;i++){
            if(i>idx && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            subsetsHelper(nums,i+1,n,ds,res);
            ds.pop_back();
        }
    }  
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        subsetsHelper(nums,0,nums.size(),ds,res);
        return res;
    }
    
    
};