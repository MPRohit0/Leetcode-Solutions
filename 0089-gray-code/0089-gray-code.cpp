class Solution {
public:
    void f(int n, int& x, vector<int>& ans){
        if(n == 0) return;

        f(n-1, x, ans); 
          

        x ^= (1 << n-1);
        ans.push_back(x);     

        f(n-1, x, ans);
    }

    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);

        int x = 0;
        f(n, x, ans);

        return ans;
    }
};