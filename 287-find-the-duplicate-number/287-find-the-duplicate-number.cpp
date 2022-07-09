class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Brute Force approach
        // Time complexity-O(nlogn), Space complexity-O(1)
        
        // int len = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<len;i++){
        //   if(nums[i-1]==nums[i]){
        //       return nums[i];
        //   }
        // }
        // return -1;
        
        // Better approach
        // Time complexity-O(n), Space complexity-O(n)
        int len = nums.size();
        vector<int>freq(len,0);
        for(int i=0;i<len;i++){
            if(freq[nums[i]]==0){
                freq[nums[i]]++;
            }
            else{
                return nums[i];
            }
        }
        return -1;
    }
};