class Solution {
public:
    
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(),t.end());
        // vector<vector<int>>dp(n,vector<int>(n,0));
        vector<int>prev(n,0),curr(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(s[i]==t[j]){
                    curr[j]=1;
                    if(i>0 && j>0) curr[j]+=prev[j-1];
                }else{
                    int f = i>0 ? prev[j] :0;
                    int l = j>0 ? curr[j-1] :0;
                    curr[j] = max(f,l);
                }
            }
            prev = curr;
        }
        return n-prev[n-1];
    }
};