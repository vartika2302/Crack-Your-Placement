class Solution {
private:
    static bool compare(int a, int b) {
        return a>b;
    }
    
    bool isPossible(int a,int b,int c) {
        if((a+b)>c && (b+c)>a && (a+c)>b) {
            return true;
        }
        return false;
    }
    
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),compare);
        int n = nums.size();
        for(int i=0,j=(i+1),k=(i+2);i<(n-2),j<(n-1),k<n;i++,j++,k++) {
            if(isPossible(nums[i],nums[j],nums[k])) return (nums[i]+nums[j]+nums[k]);
        }
        return 0;
    }
};