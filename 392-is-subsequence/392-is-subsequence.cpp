class Solution {
    
private:
    bool f(int i,int j,string& s,string& t) {
        // base case
        if(i<0) return true;
        if(j<0) return false;
        
        if(s[i]==t[j]) return f(i-1,j-1,s,t);
        else return f(i,j-1,s,t);
    }
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        return f(n-1,m-1,s,t);
    }
};