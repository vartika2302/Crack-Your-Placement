class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>dis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0) {
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,0,1};
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int d = q.front().second;
            q.pop();
            dis[row][col]=d;
            for(int i=0;i<4;i++){
                int newRow = row+dx[i];
                int newCol = col+dy[i];
                if(newRow>=0 && newCol>=0 && newRow<m && newCol<n && !vis[newRow][newCol]){
                    q.push({{newRow,newCol},d+1});
                    vis[newRow][newCol]=1;
                }
            }
        }
        
        return dis;
    }
};