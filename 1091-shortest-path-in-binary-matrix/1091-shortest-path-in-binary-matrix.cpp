class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] || grid[n-1][n-1])
            return -1;

        vector<pair<int,int>> v = {{0,0},{1,0},{0,1},{1,1},{-1,0},{0,-1},{-1,1},{1,-1},{-1,-1}};
        queue<tuple<int,int,int>> q; //i,j, d

        q.push({0,0,1}); grid[0][0] = 1;
        while(!q.empty()){
            int r,c,dis;
            tie(r,c,dis) = q.front(); q.pop();

            if(r == n-1 && c == n-1) return dis;

            for(auto &[i,j] : v){
                int nr = r + i;
                int nc = c + j;
                
                if(nr >= 0 && nc >= 0 && nr < n && nc < n && grid[nr][nc] == 0){
                    grid[nr][nc] = 1;
                    q.push({nr,nc,dis+1});
                }
            }
        }

        return -1;

    }
};