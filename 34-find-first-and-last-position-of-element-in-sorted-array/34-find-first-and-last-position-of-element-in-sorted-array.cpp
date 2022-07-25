class Solution {
public:
    
    void firstPos(vector<int>nums,int target,vector<int>&res){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target) {
                res[0]=mid;
                e=mid-1;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
    }
    
    void lastPos(vector<int>nums,int target,vector<int>&res){
        int s=0;
        int e=nums.size()-1;
        while(s<=e){
            int mid=(s+e)/2;
            if(nums[mid]==target){
                res[1]=mid;
                s=mid+1;
            }else if(nums[mid]>target){
                e=mid-1;
            }else{
                s=mid+1;
            }
        }
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>res(2,-1);
        firstPos(nums,target,res);
        lastPos(nums,target,res);
        return res;
    }
};