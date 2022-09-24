class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       set<int>s;
        for(auto it:nums){
            s.insert(it);
        }
        int ans=0;
        for(int i=0;i<nums.size();i++) {
            if(s.find(nums[i]-1)!=s.end()) continue;
            else{
                int elem = nums[i];
                int cnt=1;
                while(s.find(elem+1)!=s.end()) {
                    elem++;
                    cnt++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};