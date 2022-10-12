class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n = arr.size();
        if(n<=2) return true;
        sort(arr.begin(),arr.end());
        int d = arr[1]-arr[0];
        for(int i=0,j=(i+1);i<(n-1),j<n;i++,j++) {
            if(arr[j]-arr[i]!=d) return false;
        }
        return true;
    }
};