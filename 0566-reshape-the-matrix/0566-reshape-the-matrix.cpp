class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if((m*n)!=(r*c)) 
            return mat;
        
        int row = 0;
        int col = 0;
        
        vector<vector<int>>ans(r,vector<int>(c,0));
        
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                ans[row][col++] = mat[i][j];
                if(col==c) {
                    row++;
                    col=0;
                }
            }
        }
        return ans;
    }
};