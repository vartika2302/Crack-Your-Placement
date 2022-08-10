class Solution {
private:
    bool checkPossible(string& s1,string& s2){
        if(s1.length()!=s2.length()+1) return false;
        int first=0,second=0;
        while(first < s1.length()) {
           if(second<s2.length() && s1[first]==s2[second]){
               first++;
               second++;
           }else{
               first++;
           }
        }
        if(first==s1.length() and second==s2.length()) return true;
        return false;
    }
    
    static bool compare(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int>dp(n,1);
        int maxi=1;
        sort(words.begin(),words.end(),compare);
        for(int idx=0;idx<n;idx++){
            for(int prev_idx=0;prev_idx<idx;prev_idx++){
                if(checkPossible(words[idx],words[prev_idx]) && dp[prev_idx]+1>dp[idx]) dp[idx]=dp[prev_idx]+1;
            }
            if(dp[idx]>maxi) maxi=dp[idx];
        }
        return maxi;
    }
};