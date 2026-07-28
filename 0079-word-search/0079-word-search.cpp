class Solution {
public:
    void checker(vector<vector<char>>& board, string word, int i, int j, int p, bool& flag){
        if(flag) return;

        if(p == word.size()){
            flag = true;
            return;
        }

        if(i <0 || j < 0|| i>=board.size() || j>=board[0].size() ) return;
        if(board[i][j] == '#') return;

        if(board[i][j] != word[p]){
            return;
        }else{
            p++;
        }

        

        int i_axis[] = {-1,1,0,0};
        int j_axis[] = {0,0,-1,1};
        for(int k = 0; k < 4; k++){
            char temp = board[i][j];
            board[i][j] = '#';
            checker(board, word, i+i_axis[k], j+j_axis[k], p, flag);
            board[i][j] = temp;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i = 0; i< board.size(); i++){
            if (ans) break;
            for(int j = 0; j < board[0].size(); j++){
                checker(board, word, i, j, 0, ans);
            }
        }
        return ans;
    }
};