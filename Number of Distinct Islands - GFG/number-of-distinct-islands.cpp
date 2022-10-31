//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  private:
    void dfs(int i, int j, int srcx, int srcy, vector<vector<int>>& grid, vector<vector<int>>& visited, 
    set<pair<int,int>>& temp, int n, int m, int delx[], int dely[]) {
        visited[i][j]=1;
        temp.insert({i-srcx,j-srcy});
        
        for(int idx=0;idx<4;idx++) {
            int newi = i+delx[idx];
            int newj = j+dely[idx];
            if(newi>=0 && newi<n && newj>=0 && newj<m && !visited[newi][newj] && grid[newi][newj]==1) {
                dfs(newi,newj,srcx,srcy,grid,visited,temp,n,m,delx,dely);
            }
        }
    }
  
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        
        set<set<pair<int,int>>>s;
        
        int delx[] = {-1,0,+1,0};
        int dely[] = {0,+1,0,-1};
        
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                set<pair<int,int>>temp;
                if(!visited[i][j] && grid[i][j]==1) {
                    int srcx = i;
                    int srcy = j;
                    dfs(i,j,srcx,srcy,grid,visited,temp,n,m,delx,dely);
                    s.insert(temp);
                }
            }
        }
        
        return s.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends