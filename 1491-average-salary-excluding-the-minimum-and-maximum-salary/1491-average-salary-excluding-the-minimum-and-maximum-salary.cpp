class Solution {
public:
    double average(vector<int>& salary) {
        int n = salary.size();
        sort(salary.begin(),salary.end());
        double ans=0;
        int cnt=0;
        for(int i=1;i<(n-1);i++){
            ans+=salary[i];
            cnt++;
        }
        if(cnt==0) return ans;
        return ans/cnt;
    }
};