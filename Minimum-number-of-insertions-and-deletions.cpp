class Solution{
		

	public:
	
	int lcs(string& str1,string& str2,int n,int m) {
	    vector<int>prev(m,0),curr(m,0);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(str1[i]==str2[j]){
	                curr[j] = 1;
	                if(i>0 && j>0) curr[j]+=prev[j-1];
	            }else{
	                int f = i>0 ? prev[j] :0;
	                int l = j>0 ? curr[j-1] :0;
	                curr[j] = max(f,l);
	            }
	        }
	        prev = curr;
	    }
	    return prev[m-1];
	}
	
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    int n = str1.length();
	    int m = str2.length();
	    return n+m-(2*lcs(str1,str2,n,m));
	    
	} 
};
