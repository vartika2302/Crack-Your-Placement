class Solution {
public:
    int countOdds(int low, int high) {
        int ans;
        if(low%2!=0 && high%2!=0) {
            ans=1+((high-low)/2);
        }
        else if((low%2!=0 && high%2==0) || (low%2==0 && high%2!=0)) {
            ans=1+((high-low-1)/2);
        }
        else if(low%2==0 && high%2==0) {
            ans=(high-low)/2;
        }
        return ans;
    }
};