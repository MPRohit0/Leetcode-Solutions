class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0) return 1;
        if(n == 1) return 10;
        
        int ans = 10;
        for(int i = 2; i <= n; i++){
            int t = 9;
            for(int k = 9; k >= 9-i+2; k--){
                t *= k;
            }
            ans += t;
        }

        return ans;
    }
};