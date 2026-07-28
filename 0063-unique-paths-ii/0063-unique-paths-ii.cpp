class Solution {
public:

    int sim(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i==m-1 && j == n-1) return 1;
        if(i == m || j == n) return 0;
        if(grid[i][j] == INT_MAX) return 0;
        if(grid[i][j] != 0 && grid[i][j] != INT_MAX) return grid[i][j];

        grid[i][j] = sim(grid,i+1,j,m,n) + sim(grid,i,j+1,m,n);
        return grid[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid){
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if(obstacleGrid[m-1][n-1] == 1) return 0; 
        
        //sentinal
        for(int i = 0; i<m; i++){
            for(int j = 0; j<n; j++) if(obstacleGrid[i][j] == 1)
                obstacleGrid[i][j] = INT_MAX;
        }

        //DP
        return sim(obstacleGrid,0,0,m,n);
    }
};