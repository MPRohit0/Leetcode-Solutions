class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m,vector<int>(n,INT_MAX));
        dp[0][0] = grid[0][0];

        queue<pair<int,int>> q;
        q.push({0,0});

        while(!q.empty()){
            pair<int,int> curr = q.front();
            int i = curr.first, j = curr.second;
            q.pop();

            if(i+1< m){
                int new_val = dp[i][j] + grid[i+1][j];
                if(new_val < dp[i+1][j]){
                    dp[i+1][j] = new_val;
                q.push({i+1,j});
                }
            }

            if(j+1 < n){
                int new_val = dp[i][j] + grid[i][j+1];
                if(new_val < dp[i][j+1]){
                    dp[i][j+1] = new_val;
                q.push({i,j+1});
                }
                
            }
        }
        

        return dp[m-1][n-1];
    }
};