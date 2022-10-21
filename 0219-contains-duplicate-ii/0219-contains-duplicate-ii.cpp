class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,vector<int>>map;
        int n = nums.size();
        for(int i=0;i<n;i++) {
            map[nums[i]].push_back(i);
        }
        
        for(int i=0;i<n;i++) {
            if(map.count(nums[i])) {
                for(auto x: map[nums[i]]) {
                    if(x!=i && abs(x-i)<=k) 
                        return true;
                }
            }
        }
        return false;
    }
};