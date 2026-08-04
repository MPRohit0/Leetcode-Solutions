class Solution {
public:
    void rec(int i, int n, int k, vector<int>& temp, vector<vector<int>>& ans){
        if(temp.size() == k){
            ans.push_back(temp);
            return;
        }
        if(i > n){
            return;
        }

        //inclusion
        temp.push_back(i);
        rec(i+1, n, k, temp, ans);
        temp.pop_back();

        rec(i+1, n, k, temp, ans);

    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp; 
        vector<vector<int>> ans;
        rec(1,n,k,temp,ans);
        return ans;
    }
};