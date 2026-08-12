class Solution {
public:
    bool valid(int n, int i, int j, vector<vector<char>>& board){
        for(int k = 0; k < n; k++){
            if(board[i][k] == 'Q') return false;
            if(board[k][j] == 'Q') return false; 
        }

        //left diagonal
        int a = i, b = j;
        while(a >=0 && b >=0){
            if(board[a--][b--] == 'Q') return false;
        }

        //right diagonal
        a = i, b = j;
        while(a >=0 && b < n){
            if(board[a--][b++] == 'Q') return false;
        }

        return true;
    }

    void nQueens(int n, int i, int& ans, vector<vector<char>>& board){
        if(i == n){
            ans++; return;
        }

        for(int j = 0; j < n; j++){
            if(valid(n,i,j,board)){
                board[i][j] = 'Q';
                nQueens(n,i+1,ans,board);
                board[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<vector<char>> board(n, vector<char> (n,'.'));
        
        nQueens(n, 0, ans, board);
        return ans;
    }
};