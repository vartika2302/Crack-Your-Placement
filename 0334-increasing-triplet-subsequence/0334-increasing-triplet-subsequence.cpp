class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        int low=INT_MAX,mid=INT_MAX;
        for(int i=0;i<n;i++) {
            if(nums[i]<low) {
                low=nums[i];
            }
            else if(nums[i]>low && nums[i]<mid) {
                mid=nums[i];
            }
            else if(nums[i]>mid) return true;
        }
        return false;
    }
};