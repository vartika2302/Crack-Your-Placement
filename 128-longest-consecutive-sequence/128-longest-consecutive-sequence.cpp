class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.size()==0) return 0;
        sort(nums.begin(),nums.end());
        int maxLen=1;
        int currLen=1;
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]==prev+1) currLen++;
            else if(nums[i]!=prev) currLen=1;
            prev=nums[i];
            maxLen = max(maxLen,currLen);
        }
        return maxLen;
    }
};