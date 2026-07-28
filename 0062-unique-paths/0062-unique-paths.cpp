class Solution {
public:
    int sim(vector<vector<int>>&board, int i, int j, int m, int n){
        if(i == m-1 && j == n-1) return 1;
        if(i == m || j == n) return 0;
        if(board[i][j] != -1) return board[i][j];

        board[i][j] = sim(board,i+1,j,m,n) + sim(board,i,j+1,m,n);
        return board[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> board(m,vector<int>(n,-1));
        board[m-1][n-1] = 1;

        return sim(board,0,0,m,n);
    }
};