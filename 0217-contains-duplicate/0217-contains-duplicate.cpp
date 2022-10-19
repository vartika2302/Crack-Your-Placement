class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>ump;
        for(auto it: nums) {
            if(ump[it]==0) ump[it]++;
            else return true;
        }
        return false;
    }
};