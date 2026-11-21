class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n == 1) return true;
        if(source == destination) return true;
        
        vector<vector<int>> graph (n, vector<int>());

        for(vector<int> i : edges){
            graph[i[0]].push_back(i[1]);
            graph[i[1]].push_back(i[0]);
        }

        queue<int> proc;
        vector<int> vis(n);

        proc.push(source); vis[source] = 1;
        while(!proc.empty()){
            int curr = proc.front(); 
            proc.pop();

            for(int i: graph[curr]){
                if(i == destination) return true;
                if(!vis[i]){
                    proc.push(i);
                    vis[i] = 1;
                }
            }
        }
        return false;
    }
};