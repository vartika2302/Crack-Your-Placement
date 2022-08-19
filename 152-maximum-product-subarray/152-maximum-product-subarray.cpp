class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 187 test cases passed
        // int n = nums.size();
        // int maxProd=INT_MIN;
        // for(int i=0;i<n;i++){
        //     int prod=1;
        //     for(int j=i;j<n;j++){
        //         prod=prod*nums[j];
        //         maxProd=max(maxProd,prod);
        //     }
        // }
        // return maxProd;
        
        
        int maxProd = INT_MIN;
        int forwardProd = 1;
        int backwardProd = 1;
        for(int i=0,j=nums.size()-1;i<nums.size() && j>=0;i++,j--){
            forwardProd = forwardProd*nums[i];
            backwardProd = backwardProd*nums[j];
            maxProd = max(maxProd,max(forwardProd,backwardProd));
            if(forwardProd==0) forwardProd=1;
            if(backwardProd==0) backwardProd=1;
        }
        return maxProd;
    }
};