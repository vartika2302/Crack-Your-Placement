class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red,white,blue;
        red=white=blue=0;
        for(auto x:nums){
            if(x==0)
                red++;
            else if(x==1)
                white++;
            else
                blue++;
        }
        int i=0;
        while(red--){
            nums[i]=0;
            i++;
        }
        while(white--){
            nums[i]=1;
            i++;
        }
        while(blue--){
            nums[i]=2;
            i++;
        }
        
    }
};