class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // naive approach
        
        int n = nums.size();
        // int maxSum=INT_MIN;
        // for(int i=0;i<n;i++) {
        //     for(int j=i;j<n;j++) {
        //         int sum=0;
        //         for(int k=i;k<=j;k++) {
        //             sum+=nums[k];
        //         }
        //         maxSum = max(maxSum,sum);
        //     }
        // }
        // return maxSum;
        
        
        
        
        // O(N^2)
//          int maxSum=INT_MIN;
//         for(int i=0;i<n;i++) {
//             int sum=0;
           
//             for(int j=i;j<n;j++) {
//                 sum+=nums[j];
//                 maxSum=max(maxSum,sum);
//             }
//         }
//         return maxSum;
        
        
        // O(N)
        // Kadane's algo
        int currsum=0;
        int maxsum=INT_MIN;
        for(int i=0;i<n;i++) {
            currsum+=nums[i];
            maxsum=max(maxsum,currsum);
            if(currsum<0) currsum=0;
        }
        return maxsum;
        
        
    }
};