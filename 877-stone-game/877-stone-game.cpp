class Solution {
private:
    int f(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if(i>j) return 0;
        if(i==j) return piles[i];
        if(i+1==j) return max(piles[i],piles[j]);
        if(dp[i][j]!=-1) return dp[i][j];
        int leftChoose = piles[i]+min(piles[i+1]+f(i+2,j,piles,dp),piles[j]+f(i+1,j-1,piles,dp));
        int rightChoose = piles[j]+min(piles[i]+f(i+1,j-1,piles,dp),piles[j-1]+f(i,j-2,piles,dp));
        return dp[i][j]=max(leftChoose,rightChoose);
    }
    
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int mark = (n-1)/2;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int ans = f(0,n-1,piles,dp);
        if(ans>mark) return true;
        return false;
    }
};