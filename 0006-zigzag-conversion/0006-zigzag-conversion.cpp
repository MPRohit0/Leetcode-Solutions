class Solution {
public:
    string convert(string s, int a) {
        if(s.size() == 1 || a == 1) return s;
        
        int n = a;
        int m = ceil((double)(n - 1) / (2*n - 2) * s.size());

        vector<vector<char>> sim(n, vector<char> (m,'#'));


        int i = 0;
        int r = 0, c = 0;
        while(i < s.size()){
            while(i < s.size() && r < n){
                sim[r++][c] = s[i++];
            }
            r--;

            r--; c++;
            while(i < s.size() && r > 0){
                sim[r--][c++] = s[i++];
            }   
        }

        string ans;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(sim[i][j] != '#') ans += sim[i][j]; 
            }
        }
        return ans;
    }
};