class Solution {
public:
    
    void permuteHelper(vector<int>& nums, int n, vector<int>& ds, map<int,int>& mpp, vector<vector<int>>&res){
        if(ds.size() == n) {
            res.push_back(ds);
            return;
        }
        for(int i=0;i<n;i++){
            if(!mpp[i]){
                mpp[i]=1;
                ds.push_back(nums[i]);
                permuteHelper(nums,n,ds,mpp,res);
                mpp[i]=0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>res;
        map<int,int>mpp;
        vector<int>ds;
        permuteHelper(nums,nums.size(),ds,mpp,res);
        return res;
    }
};