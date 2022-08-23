class Solution {
private:
    void dfs(int sr,int sc,vector<vector<int>>& image,int color,int prev_color,vector<vector<int>>& vis,int n,int m) {
        vis[sr][sc]=1;
        image[sr][sc]=color;
        // left
        if(sc-1>=0 && sc-1<m && image[sr][sc-1]==prev_color && !vis[sr][sc-1]){
            vis[sr][sc-1]=1;
            image[sr][sc-1]=color;
            dfs(sr,sc-1,image,color,prev_color,vis,n,m);
        }
        // right
        if(sc+1>=0 && sc+1<m && image[sr][sc+1]==prev_color && !vis[sr][sc+1]){
            vis[sr][sc+1]=1;
            image[sr][sc+1]=color;
            dfs(sr,sc+1,image,color,prev_color,vis,n,m);
        }
        // top
        if(sr-1>=0 && sr-1<n && image[sr-1][sc]==prev_color && !vis[sr-1][sc]){
            vis[sr-1][sc]=1;
            image[sr-1][sc]=color;
            dfs(sr-1,sc,image,color,prev_color,vis,n,m);
        }
        // bottom
        if(sr+1>=0 && sr+1<n && image[sr+1][sc]==prev_color && !vis[sr+1][sc]){
            vis[sr+1][sc]=1;
            image[sr+1][sc]=color;
            dfs(sr+1,sc,image,color,prev_color,vis,n,m);
        }
    }
    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int prev_color=image[sr][sc];
        dfs(sr,sc,image,color,prev_color,vis,n,m);
        return image;
    }
};