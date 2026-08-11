class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int> (n,0));

        int t = 1;
        int r = n - 1, b = n - 1;
        int l = 0, u = 0;

        while (l <= r && u <= r){
            for(int j = l; j <= r; j++){
                mat[u][j] = t++;
            }
            u++;

            for(int i = u; i <= b; i++){
                mat[i][r] = t++;
            }
            r--;

            for(int j = r; j >= l; j--){
                mat[b][j] = t++;
            }
            b--;

            for(int i = b; i >= u; i--){
                mat[i][l] = t++;
            }
            l++;
        }

        return mat;
    }
};