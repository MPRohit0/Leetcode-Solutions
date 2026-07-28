class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col, int n){
        //horizontal
        for(int j=0;j<n;j++) if(board[row][j] == 'Q') return false;
        for(int i=0;i<n;i++) if(board[i][col] == 'Q') return false;

        //left diagonal
        for(int i=row,j=col; i>=0&&j>=0;j--,i--) if(board[i][j]=='Q') return false;
        for(int i=row,j=col; i>=0&&j<n;j++,i--) if(board[i][j]=='Q') return false; 

        return true;
    }

    void nQueens(vector<string>& board, int row, int n, vector<vector<string>>& ans){
        if(row==n){
            ans.push_back(board);
            return;
        }


        for(int i = 0;i<n;i++){
            if(isSafe(board, row, i, n)){
                board[row][i] = 'Q';
                nQueens(board,row+1,n,ans);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));

        nQueens(board,0,n,ans);
        return ans;
    }
};