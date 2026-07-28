class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()|| matrix[0].empty()) return vector<int>{};
        
        int t = 0, b = matrix.size()-1, l = 0 , r = matrix[0].size()-1;
        vector<int> ans;

        
        while(r>=l&&b>=t){
            //t
            for(int i=l;i<=r;i++){
                ans.push_back(matrix[t][i]);
            }
            t++;

            //r
            for(int i=t;i<=b;i++){
                ans.push_back(matrix[i][r]);
            }
            r--;

            //b
            if(t<=b){
                for(int i = r;i>=l;i--){
                    ans.push_back(matrix[b][i]);
                }
                b--;
            }

            if(l<=r){
                for(int i=b;i>=t;i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
            }

        }
        
        return ans;
        
    }
};