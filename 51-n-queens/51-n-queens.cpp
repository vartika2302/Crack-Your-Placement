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
};