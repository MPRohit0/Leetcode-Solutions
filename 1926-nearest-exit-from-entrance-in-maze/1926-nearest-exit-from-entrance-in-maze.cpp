class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        queue<tuple<int,int,int>> q; //r c count
        q.push({entrance[0], entrance[1], 0});
        maze[entrance[0]][entrance[1]] = '+';

        while(!q.empty()){
            auto [r,c,dis] = q.front(); q.pop();

            //answer validataion
            if(dis != 0){
                if(r == 0 || r == maze.size()-1 || c == 0 || c == maze[0].size()-1){
                    return dis;
                }
            }

            //bfs
            vector<int> ver = {1,-1,0,0};
            vector<int> hor = {0,0,1,-1};

            for(int k = 0; k < 4; k++){
                int nr = r + ver[k];
                int nc = c + hor[k];

                if(nr >=0 && nc >=0 && nr < maze.size() && nc < maze[0].size() && maze[nr][nc]!= '+'){
                    q.push({nr,nc,dis+1});
                    maze[nr][nc] = '+';
                }
            }
        }

        return -1;

    }
};