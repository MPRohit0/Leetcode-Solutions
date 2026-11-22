class Solution {
public:
    int numSquares(int n) {
        if(n < 3) return n;
        
        vector<int> dp(n + 1, INT_MAX); 
        dp[0] = 0;

        for(int c = 1; c <= n; c++){
            if(c*c > n) break;

            for(int i = c*c; i <= n; i++){
                dp[i] = min(dp[i], dp[i-(c*c)] + 1);
            }
        }

        return dp[n];
    }
};