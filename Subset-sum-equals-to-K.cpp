class Solution{   
public:
    bool f(int idx,int sum,vector<int>& arr,vector<vector<int>>& dp) {
        if(sum==0) return true;
        if(idx==0) return arr[0]==sum;
        if(dp[idx][sum]!=-1) return dp[idx][sum];
        bool take=false;
        if(sum>=arr[idx]) take=f(idx-1,sum-arr[idx],arr,dp);
        bool not_take=f(idx-1,sum,arr,dp);
        return dp[idx][sum]=take || not_take;
    }

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n=arr.size();
        vector<vector<int>>dp(100,vector<int>(1e5,-1));
        return f(n-1,sum,arr,dp);
    }
};
