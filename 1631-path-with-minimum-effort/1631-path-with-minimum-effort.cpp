class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();

        vector<vector<int>> dis(n, vector<int>(m,INT_MAX));
        priority_queue<tuple<int,int,int>> pq; //-w, i, j

        dis[0][0] = 0; pq.push({0,0,0});
        vector<pair<int,int>> dir_vec = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!pq.empty()){
            auto curr = pq.top(); pq.pop();
            int a,r,c;
            tie(a,r,c) = curr;

            if(r == n-1 && c == m-1) return -a;
            if(dis[r][c] < a) continue;
            
            for(auto &[i,j] : dir_vec){
                int nr = r + i, nc = c + j;

                if(nr >= 0 && nc >=0 && nr < n && nc < m){
                    int maybe = max(dis[r][c],abs(heights[r][c] - heights[nr][nc]));
                    if(maybe < dis[nr][nc]){
                        dis[nr][nc] = maybe;
                        pq.push({-maybe, nr, nc});
                    }
                }
            }
        }

        return -1;
    }
};