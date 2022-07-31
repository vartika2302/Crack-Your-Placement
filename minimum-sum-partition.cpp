class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int totsum=0;
	    for(int i=0;i<n;i++){
	        totsum+=arr[i];
	    }
	    int sum=totsum;
	    vector<vector<bool>>dp(n,vector<bool>(sum+1,0));
	    for(int idx=0;idx<n;idx++){
	        dp[idx][0]=true;
	    }
	    if(arr[0]<=sum) dp[0][arr[0]]=true;
	    
	    for(int idx=1;idx<n;idx++){
	        for(int target=1;target<=sum;target++){
	            bool not_take=dp[idx-1][target];
	            bool take=false;
	            if(target>=arr[idx]) take=dp[idx-1][target-arr[idx]];
	            dp[idx][target]=take||not_take;
	        }
	    }
	    
	    int mini=1e9;
	    for(int target=0;target<=sum;target++){
	        if(dp[n-1][target]==true) mini=min(mini,abs((sum-target)-target));
	    }
	    return mini;
	} 
};
