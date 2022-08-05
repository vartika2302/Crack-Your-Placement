class Solution {
public:
    int longestCommonSubsequence(string& word1,string& word2,int n,int m) {
       vector<int>prev(n,0),curr(m,0);
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(word1[i]==word2[j]) {
                   curr[j] = 1;
                    if(i>0 && j>0) curr[j]+=prev[j-1];
               }
               else{
                   int f = i>0 ? prev[j] :0;
                   int l = j>0 ? curr[j-1] :0;
                   curr[j] = max(f,l);
               }
           }
           prev = curr;
       }
        return prev[m-1];
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        int lcs = longestCommonSubsequence(word1,word2,n,m);
        return n+m-(2*lcs);
    }
};