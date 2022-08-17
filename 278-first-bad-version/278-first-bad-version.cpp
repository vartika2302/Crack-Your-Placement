// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long int s=1;
        long long int e=n;
        int ans=-1;
        while(s<=e) {
            long long int mid = (s+e)/2;
            if(isBadVersion((int)mid)) {
                ans=mid;
                e=mid-1;
            }
            else {
                s=mid+1;
            }
        }
        return ans;
    }
};