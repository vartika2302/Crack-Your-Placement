// TC - O(N*M)+O(4*N*M) ---> O(N*M)
// SC - O(N*M)+O(N*M)
class Solution {
private:
    void dfs(int row, int col, vector<vector<int>>&image, vector<vector<int>>& ans, int color, int initialColor,int drow[], int dcol[],int n,int m){
        ans[row][col]=color;
        for(int i=0;i<4;i++){
            int newRow = row+drow[i];
            int newCol = col+dcol[i];
            if(newRow>=0 && newCol>=0 && newRow<n && newCol<m && image[newRow][newCol]==initialColor && ans[newRow][newCol]!=color){
                dfs(newRow,newCol,image,ans,color,initialColor,drow,dcol,n,m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>>ans = image;
        int initialColor = image[sr][sc];
        int drow[] = {-1,0,+1,0};
        int dcol[] = {0,-1,0,+1};
        dfs(sr,sc,image,ans,color,initialColor,drow,dcol,n,m);
        return ans;
    }
};