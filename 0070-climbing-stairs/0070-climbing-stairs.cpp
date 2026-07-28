class Solution {
public:
    int step(int n, vector<int>& dp){
        if(n<0) return 0;
        
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n] = step(n-1, dp) + step(n-2, dp);
        return dp[n];
    }
    
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        dp[0] = 1;
        dp[1] = 1;

        int ans = step(n, dp);
        return ans;
    }
};