class Solution{
	public:
	int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    int n = nums.size();
	    vector<int>dp1(n,1);
	    for(int idx=0;idx<n;idx++){
	        for(int prev=0;prev<idx;prev++){
	            if(nums[idx]>nums[prev] && dp1[idx]<1+dp1[prev]){
	                dp1[idx] = 1+dp1[prev];
	            }
	        }
	    }
	    
	    vector<int>dp2(n,1);
	    for(int idx=(n-1);idx>=0;idx--){
	        for(int prev=(n-1);prev>idx;prev--){
	            if(nums[idx]>nums[prev] && dp2[idx]<1+dp2[prev]){
	                dp2[idx] = 1+dp2[prev];
	            }
	        }
	    }
	    
	    int maxi=1;
	    for(int i=0;i<n;i++){
	        maxi=max(maxi,dp1[i]+dp2[i]-1);
	    }
	    return maxi;
	}
};
