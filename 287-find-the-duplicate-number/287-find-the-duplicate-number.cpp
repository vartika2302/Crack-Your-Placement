class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        /********* Brute Force approach **********/
        // Time complexity-O(nlogn), Space complexity-O(1)
        
        // int len = nums.size();
        // sort(nums.begin(),nums.end());
        // for(int i=1;i<len;i++){
        //   if(nums[i-1]==nums[i]){
        //       return nums[i];
        //   }
        // }
        // return -1;
        
        
        /********* Better approach ***********/
        // Time complexity-O(n), Space complexity-O(n)
        
        // int len = nums.size();
        // vector<int>freq(len,0);
        // for(int i=0;i<len;i++){
        //     if(freq[nums[i]]==0){
        //         freq[nums[i]]++;
        //     }
        //     else{
        //         return nums[i];
        //     }
        // }
        // return -1;
        
        
        /******** Optimal approach *********/
        // Time complexity-O(n), Space complexity-O(1)
        // Linked List cycle method(Tortoise/runner method)
        
        int slow=nums[0];
        int fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        fast=nums[0];
       while(slow!=fast){
           slow=nums[slow];
           fast=nums[fast];
       }
        
        return slow;
    }
};