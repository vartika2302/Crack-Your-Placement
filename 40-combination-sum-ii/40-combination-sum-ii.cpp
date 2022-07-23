class Solution {
public:
    // gives tle
//     void combinationHelper(vector<int>&candidates,int idx,int target,set<vector<int>>&s,vector<int>&ds) {
//         if(idx == candidates.size()) {
//             if(target == 0) {
//                 s.insert(ds);
//             }
//             return;
//         }
//         if(candidates[idx]<=target){
//             ds.push_back(candidates[idx]);
//             combinationHelper(candidates,idx+1,target-candidates[idx],s,ds);
//             ds.pop_back();
//         }
//         combinationHelper(candidates,idx+1,target,s,ds);
//     }
    
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
//         sort(candidates.begin(),candidates.end());
//         set<vector<int>>s;
//         vector<int>ds;
//         combinationHelper(candidates,0,target,s,ds);
//         vector<vector<int>>res(s.begin(),s.end());
//         return res;
//     }
    
    void combinationHelper(vector<int> candidates,int idx,int target,vector<int>& ds,vector<vector<int>>& res) {
        if(target==0){
            res.push_back(ds);
            return;
        }
        for(int i=idx;i<candidates.size();i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            ds.push_back(candidates[i]);
            combinationHelper(candidates,i+1,target-candidates[i],ds,res);
            ds.pop_back();
        }
        
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>ds;
        // because we need sorted combinations
        sort(candidates.begin(),candidates.end());
        combinationHelper(candidates,0,target,ds,res);
        return res;
    }
    
    
    
};