class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negEl=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0) return 0;
            else if(nums[i]<0) negEl++;
        }
        return negEl%2!=0 ? -1 : 1;
    }
};