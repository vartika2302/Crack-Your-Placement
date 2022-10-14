class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int ans=0;
        int n = arr.size(); 
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int num = (j-i+1);
                if(num&1) {
                    int sum=0;
                    for(int k=i;k<=j;k++) {
                        sum+=arr[k];
                    }
                    ans+=sum;
                }
            }
        }
        return ans;
    }
};