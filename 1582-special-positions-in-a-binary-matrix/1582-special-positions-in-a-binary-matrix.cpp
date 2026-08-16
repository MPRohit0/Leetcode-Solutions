class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> h(n, 0);
        vector<int> v(m,0);

        for(int i = 0;i < n; i++){
            for(int j = 0; j < m; j++){
                h[i]+=mat[i][j];
                v[j]+=mat[i][j];
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(h[i] == 1){
                for(int j = 0; j < m; j++){
                    if(mat[i][j] == 1 && v[j] == 1){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};