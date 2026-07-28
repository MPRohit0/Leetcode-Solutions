class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        int m = 9;
        
        //horizontal check
        unordered_set<int> a;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(board[i][j] == '.') continue;
                
                if(a.count(board[i][j])) return false;
                a.insert(board[i][j]);
            }
            a.clear();
        }

        //vertical check
        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(board[i][j] == '.') continue;

                if(a.count(board[i][j])) return false;
                a.insert(board[i][j]);
            }
            a.clear();
        }

        //grids
        unordered_set<int> box[9];
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.') continue;

                int idx = (i/3)*3 + (j/3);

                if(box[idx].count(board[i][j])) return false;
                box[idx].insert(board[i][j]);
            }
        }

        return true;
    }
};