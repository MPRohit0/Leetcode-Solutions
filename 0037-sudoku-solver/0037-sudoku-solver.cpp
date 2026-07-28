class Solution {
public:
    bool checker(vector<vector<char>>& board, int row, int col,char c){
        for(int j = 0;j<9;j++){
            if(board[row][j]==c){
                return false;
            }
            if(board[j][col]==c){
                return false;
            }
        }  

        //box
        int rowStart = 3 * (row/3);
        int colStart = 3 * (col/3);
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[rowStart+i][j+colStart]==c){
                    return false;
                }
            }
        }

        return true;

    }
    
    void solver(vector<vector<char>>& board, int row, int col, bool& flag){
        
        if(row>=9){
            row = 0;
            col++;
        }
        
        if(col>=9){
            flag = true;
            return;
        }

        if(board[row][col]=='.'){
            for(int i=1;i<=9;i++){
                if(checker(board,row,col,'0'+i)){
                    board[row][col] = '0'+i;
                    solver(board,row+1,col,flag);
                    if(flag) return;
                    board[row][col] = '.';
                }
            }
        }else{
            int i = 1;
            while((row+i)<9&&board[row+i][col]!='.') i++;
            solver(board,row+i,col,flag);
        }
        
    }

    void solveSudoku(vector<vector<char>>& board) {
        bool flag = false;
        solver(board,0,0,flag);
    }
};