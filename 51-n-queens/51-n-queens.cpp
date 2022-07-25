class Solution {
public:
    
    bool isSafe(int row,int col,vector<string> board,int n){
        int dummyRow = row;
        int dummyCol = col;
        
        // Check left upward diagonal
        while(row>=0 && col>=0){
            if(board[row][col]=='Q') return false;
            row--;
            col--;
        }
        
        // Check left side
        row = dummyRow;
        col = dummyCol;
        while(col>=0){
            if(board[row][col]=='Q') return false;
            col--;
        }
        
        // Check bottom left
        row = dummyRow;
        col = dummyCol;
        while(col>=0 && row<n){
            if(board[row][col]=='Q') return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(int col,vector<vector<string>>& res,vector<string>& board,int n){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,res,board,n);
                board[row][col]='.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        solve(0,res,board,n);
        return res;
    }
    
    
    
     // Optimal Solution
    
    void solve(int col,vector<string>& board, vector<vector<string>>& res, vector<int>& leftRow, vector<int>& lowerDiagonal, vector<int>& upperDiagonal, int n){
        if(col == n){
            res.push_back(board);
            return;
        }
        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && lowerDiagonal[row+col]==0 && upperDiagonal[n-1+col-row]==0){
                board[row][col]='Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1,board,res,leftRow,lowerDiagonal,upperDiagonal,n);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row+col] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n){
        vector<vector<string>> res;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            board[i] = s;
        }
        vector<int> leftRow(n,0), upperDiagonal((2*n)-1,0), lowerDiagonal((2*n)-1,0);
        solve(0,board,res,leftRow,lowerDiagonal,upperDiagonal,n);
        return res;
    }
};
