class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        q.push({{entrance[0],entrance[1]},0});
        vis[entrance[0]][entrance[1]] = 1;
        int dx[] = {-1,0,+1,0};
        int dy[] = {0,+1,0,-1};
        while(!q.empty()) {
            int cx = q.front().first.first;
            int cy = q.front().first.second;
            int d = q.front().second;
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = cx+dx[i];
                int ny = cy+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && !vis[nx][ny] && maze[nx][ny]=='.') {
                    if(nx==0 || ny==0 || nx==(m-1) || ny==(n-1)) 
                        return d+1;
                    q.push({{nx,ny},d+1});
                    vis[nx][ny]=1;
                }
            }
        }
        return -1;
    }
};