class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> vis(n);

        queue<int> q;
        q.push(0); vis[0] = 1;
        while(!q.empty()){
            int curr = q.front();
            q.pop();

            for(int v : rooms[curr]){
                if(!vis[v]){
                    q.push(v); 
                    vis[v] = 1;
                }
            }
        }

        return accumulate(vis.begin(), vis.end(), 0) == n;
    }
};