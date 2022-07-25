class Solution{
    public:
    
    void solve(int i,int j,vector<vector<int>>& m,int n,vector<string>& ans,vector<vector<int>>& visited,
    string move) {
        if(i==n-1 && j==n-1) {
            ans.push_back(move);
            return;
        }
        
        // Lexicographical order - {D,L,R,U}
        // Downward step
        if(i+1<n && visited[i+1][j]==0 && m[i+1][j]==1){
            visited[i][j]=1;
            solve(i+1,j,m,n,ans,visited,move+"D");
            visited[i][j]=0;
        }
        
        // Leftward step
        if(j-1>=0 && visited[i][j-1]==0 && m[i][j-1]==1){
            visited[i][j]=1;
            solve(i,j-1,m,n,ans,visited,move+"L");
            visited[i][j]=0;
        }
        
        // Rightward step
        if(j+1<n && visited[i][j+1]==0 && m[i][j+1]==1){
            visited[i][j]=1;
            solve(i,j+1,m,n,ans,visited,move+"R");
            visited[i][j]=0;
        }
        
        // Upward step
        if(i-1>=0 && visited[i-1][j]==0 && m[i-1][j]==1){
            visited[i][j]=1;
            solve(i-1,j,m,n,ans,visited,move+"U");
            visited[i][j]=0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        // TC-O(4^(n*m))
        // SC-O(n*m)
        vector<string> ans;
        vector<vector<int>> visited(n,vector<int>(n,0));
        if(m[0][0]==1) solve(0,0,m,n,ans,visited,"");
        return ans;
    }
};

    
